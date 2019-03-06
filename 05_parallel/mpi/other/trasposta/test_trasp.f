      PROGRAM test_trasp

      IMPLICIT NONE

      INTEGER ldx, ldy

      REAL*8, ALLOCATABLE :: x(:,:)
      REAL*8, ALLOCATABLE :: y(:,:)
      INTEGER i, j, k
      INTEGER n, m, bsiz
      REAL*8 t1, t2, cclock
      EXTERNAL cclock 

      ldx = 4096
      ldy = 4096
      n = 4096
      m = 4096 

      ALLOCATE( x( ldx, m ), y( ldy, n ) )

      ! definisci la matrice da trasporre
      do j = 1, m
        do i = 1, n
          x(i,j) = REAL(i + (j-1)*n)
        end do
      end do

      t1 = cclock()
      CALL trasponi(1,x,ldx,y,ldy,n,m,50) 
      t2 = cclock()

      write(6,fmt='(A25,D14.6)') ' trasposta ', t2-t1

      t1 = cclock()
      CALL trasponi(2,x,ldx,y,ldy,n,m,50) 
      t2 = cclock()

      write(6,fmt='(A25,D14.6)') ' trasposta a blocchi ', t2-t1

      
      DEALLOCATE( x, y )

      ALLOCATE( x( ldx, m ), y( ldy, n ) )

      do bsiz = 5, 95, 10
         t1 = cclock()
         CALL trasponi(2,x,ldx,y,ldy,n,m,bsiz) 
         t2 = cclock()
         write(6,fmt='(I4,F10.7)') bsiz, t2-t1
      end do

      DEALLOCATE( x, y )

      END


      SUBROUTINE trasponi(what, x, ldx, y, ldy, n, m, bsiz)
        IMPLICIT NONE
        INTEGER ldx, ldy, n, m, what, bsiz
        REAL*8  x(ldx, m), y(ldy, n)
        REAL*8  buf( bsiz, bsiz )
        INTEGER i, j, k, d, nb, mb, ib, jb, ioff, joff
        INTEGER iind, jind
        REAL*8  bswp

        if( n .gt. ldx ) then
          write(6,fmt='("trasponi: inconsistent ldx and n")')
        end if
        if( m .gt. ldy ) then
          write(6,fmt='("trasponi: inconsistent ldy and m")')
        end if

        nb = n / bsiz 
        mb = m / bsiz 

        if( what .eq. 1 ) then

            do i=1,n
              do j=1,m
                y(j,i) = x(i,j)
              enddo
            enddo

        else if( what .eq. 2 ) then

            do ib = 1, nb
              ioff = (ib-1) * bsiz
              do jb = 1, mb
                joff = (jb-1) * bsiz
                do j = 1, bsiz
                  do i = 1, bsiz
                    buf(i,j) = x(i+ioff, j+joff)
                  enddo
                enddo
                do j = 1, bsiz
                  do i = 1, j-1
                    bswp = buf(i,j)
                    buf(i,j) = buf(j,i) 
                    buf(j,i) = bswp
                  enddo
                enddo
                do i=1,bsiz
                  do j=1,bsiz
                    y(j+joff, i+ioff) = buf(j,i)
                  enddo
                enddo
              enddo
            enddo

            IF( min( 1, MOD(n, bsiz) ) .GT. 0 ) THEN
              ioff = nb * bsiz
              do jb = 1, mb
                joff = (jb-1) * bsiz
                do j = 1, bsiz
                  do i = 1, MIN(bsiz, n-ioff)
                    buf(i,j) =  x(i+ioff, j+joff)
                  enddo
                enddo
                do i = 1, MIN(bsiz, n-ioff)
                  do j = 1, bsiz
                    y(j+joff,i+ioff) = buf(i,j)
                  enddo
                enddo
              enddo
            END IF

            IF( MIN(1, MOD(m, bsiz)) .GT. 0 ) THEN
              joff = mb * bsiz
              do ib = 1, nb
                ioff = (ib-1) * bsiz
                do j = 1, MIN(bsiz, m-joff)
                  do i = 1, bsiz
                    buf(i,j) =  x(i+ioff, j+joff)
                  enddo
                enddo
                do i = 1, bsiz
                  do j = 1, MIN(bsiz, m-joff)
                    y(j+joff,i+ioff) = buf(i,j)
                  enddo
                enddo
              enddo
            END IF

            IF( MIN(1,MOD(n,bsiz)).GT.0 .AND.  &
     &          MIN(1,MOD(m,bsiz)).GT.0 ) THEN
              joff = mb * bsiz
              ioff = nb * bsiz
              do j = 1, MIN(bsiz, m-joff)
                do i = 1, MIN(bsiz, n-ioff)
                  buf(i,j) =  x(i+ioff, j+joff)
                enddo
              enddo
              do i = 1, MIN(bsiz, n-ioff)
                do j = 1, MIN(bsiz, m-joff)
                  y(j+joff,i+ioff) = buf(i,j)
                enddo
              enddo
            END IF

        else

            write(6,fmt='("trasponi: undefined method")')

        end if

        RETURN
      END

