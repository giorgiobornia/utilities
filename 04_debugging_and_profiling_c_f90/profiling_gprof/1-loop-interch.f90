program test

  implicit none

! Show cache influence on code performances
! "good" loop sums matrixes in column order (best)
! "bad" loop sums matrixes in row order

! ifort 1-loop-interch.f90 -O3 -o loop-interch
! ./loop-interch
! time ./loop-interch

! ifort 1-loop-interch.f90 -O3 -xW -o loop-interch_VECT
! ./loop-interch_VECT
! time ./loop-interch_VECT


  real, allocatable :: a(:,:), b(:,:), c(:,:)
  real alpha 
  integer i, j, dim, niter, t

  dim = 5000
  niter = 2
  alpha = sqrt(1.)

  allocate(a(dim, dim))
  allocate(b(dim, dim))
  allocate(c(dim, dim))

  a = 0.
  b = 1.
  c = 2.

!!!!!!!!!!!!!!!!!!!!!!!!! GOOD START !!!!!!!!!!!!!!!!!!!!!!!
  write(*,*) "good start"

  do t=1, niter

     do j=1, dim
        do i=1, dim
           a(i,j) = a(i,j) + b(i,j) + c(i,j) + alpha
        enddo
     enddo

  enddo

  write(*,*) "good end"
!!!!!!!!!!!!!!!!!!!!!!!!! GOOD END !!!!!!!!!!!!!!!!!!!!!!!
  if(alpha < -1) write(*,*) a, b, c

  a = 0.
  b = 1.
  c = 2.
!!!!!!!!!!!!!!!!!!!!!!!!! BAD START !!!!!!!!!!!!!!!!!!!!!!!
  write(*,*) "bad start"

  do t=1, niter

     do j=1, dim
        do i=1, dim
           a(j,i) = a(j,i) + b(j,i) + c(j,i) + alpha
        enddo
     enddo

  enddo
  write(*,*) "bad end"
!!!!!!!!!!!!!!!!!!!!!!!!! BAD END !!!!!!!!!!!!!!!!!!!!!!!

  deallocate(a)
  deallocate(b)
  deallocate(c)

end program test
