program test

  implicit none
!=================================================================================!
! Test gprof
! Disable inline to understand profiler
! export GMON_OUT_PREFIX=gmon.out    --> pid on gmon.out --> profile MPI codes

! 0 -
! ifort 4-sincos.f90 -O3 -o sincos
! ./sincos

! 1 -
! ifort 4-sincos.f90 -O3 -o sincos -xW
! ./sincos

! 2 -
! ifort 4-sincos.f90 -ip_no_inlining -O0 -pg -o sincos
! ./sincos
! gprof sincos gmon.out
!    --> create code profile 

! 3 -
! ifort 4-sincos.f90 -ip_no_inlining -O0 -pg -o sincos
! ./sincos
! gprof -l sincos gmon.out
!    --> create code profile at line level

! 4 - (Con o senza -pg)
! ifort 4-sincos.f90 -ip_no_inlining -O0 -pg -o sincos
! time ./sincos
! ifort 4-sincos.f90 -ip_no_inlining -O0 -o sincos
! time ./sincos

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
  dim = 100
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
           a=exp(a*j+i)
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
           b=sin(a*j+i)
        enddo
     enddo
     
  enddo
  t2 = etime(tt)
  write(*,*) "bad end"
  write(6,*) "time =",t2-t1
!!!!!!!!!!!!!!!!!!!!!!!!! BAD END !!!!!!!!!!!!!!!!!!!!!!!

  deallocate(a)
  deallocate(b)
  deallocate(c)

end program
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
