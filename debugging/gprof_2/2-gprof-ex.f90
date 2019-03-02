program test

  implicit none
!=================================================================================!
! Test gprof
! Disable inline to understand profiler
! export GMON_OUT_PREFIX=gmon.out    --> pid on gmon.out --> profile MPI codes

! 0 -
! ifort 2-gprof-ex.f90 -O3 -o gprof-ex
! ./gprof-ex

! 1 -
! ifort 2-gprof-ex.f90 -O3 -o gprof-ex -xW
! ./gprof-ex

! 2 -
! ifort 2-gprof-ex.f90 -ip_no_inlining -O0 -pg -o gprof-ex
! ./gprof-ex
	! gprof gprof-ex gmon.<pid>
!    --> create code profile 

! 3 -
! ifort 2-gprof-ex.f90 -ip_no_inlining -O0 -pg -o gprof-ex
! ./gprof-ex
! gprof -l gprof-ex gmon.<pid>
!    --> create code profile at line level

! 4 - (Con o senza -pg)
! ifort 2-gprof-ex.f90 -ip_no_inlining -O0 -pg -o gprof-ex
! time ./gprof-ex
! ifort 2-gprof-ex.f90 -ip_no_inlining -O0 -o gprof-ex
! time ./gprof-ex
!=================================================================================!
!VALGRIND
!module load valgrind/3.2.3
! ifort 2-gprof-ex.f90 -O3 -o gprof-ex
!valgrind  -v --tool=cachegrind ./gprof-ex
!kcachegrind cachegrind.out.3493

! ifort 2-gprof-ex.f90 -ip_no_inlining -O0 -g -o gprof-ex

!valgrind  -v --tool=cachegrind ./gprof-ex
!kcachegrind cachegrind.out.3493


!--I1=<size>,<associativity>,<line size>
!Specify the size, associativity and line size of the level 1 instruction cache.

!--D1=<size>,<associativity>,<line size>
!Specify the size, associativity and line size of the level 1 data cache.

!--L2=<size>,<associativity>,<line size>
!Specify the size, associativity and line size of the level 2 cache.
!=================================================================================!
  
  real, allocatable :: a(:,:), b(:,:), c(:,:)
  real alpha 
  integer i, j, dim, niter, t
  
  real*4 tt(2),tempo, etime, t1, t2
  external etime

!   dim = 5000
  dim = 3000
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
  t1 = etime(tt)
  do t=1, niter

     do j=1, dim
        do i=1, dim
           call good_assign(i, j, dim, a, b, c, alpha)
        enddo
     enddo
     
  enddo
  t2 = etime(tt)
  write(*,*) "good end"
  write(6,*) "time =",t2-t1
!!!!!!!!!!!!!!!!!!!!!!!!! GOOD END !!!!!!!!!!!!!!!!!!!!!!!

  if(alpha < -1) write(*,*) a, b, c

  a = 0.
  b = 1.
  c = 2.

!!!!!!!!!!!!!!!!!!!!!!!!! BAD START !!!!!!!!!!!!!!!!!!!!!!!
  write(*,*) "bad start"
  t1 = etime(tt)
  do t=1, niter

     do j=1, dim
        do i=1, dim
           call bad_assign(i, j, dim, a, b, c, alpha)
        enddo
     enddo
     
  enddo
  t2 = etime(tt)
  write(*,*) "bad end"
  write(6,*) "time =",t2-t1
!!!!!!!!!!!!!!!!!!!!!!!!! BAD END !!!!!!!!!!!!!!!!!!!!!!!

call prova(1, 1, dim, a, b, c, alpha)
  
  deallocate(a)
  deallocate(b)
  deallocate(c)

end program
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine good_assign(i1, i2, dim, a, b, c, alpha)

  implicit none 

  integer i1, i2, dim
  real a(dim, dim), b(dim, dim), c(dim, dim)
  real alpha
  
  a(i1,i2) = a(i1,i2) + b(i1,i2) + c(i1,i2) + alpha

end subroutine 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine bad_assign(i1, i2, dim, a, b, c, alpha)

  implicit none 

  integer i1, i2, dim
  real a(dim, dim), b(dim, dim), c(dim, dim)
  real alpha


  a(i2,i1) = a(i2,i1) + b(i2,i1) + c(i2,i1) + alpha

end subroutine 
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
subroutine prova(i1, i2, dim, a, b, c, alpha)
  call bad_assign(i1, i2, dim, a, b, c, alpha)
end subroutine