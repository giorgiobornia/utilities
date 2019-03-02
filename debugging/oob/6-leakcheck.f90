program test_oob

  implicit none

! test memory leaks problem
! ulimit -v 400000 
! to don't crash the node
! run on /scratch to dump core without finish the quota
! 0 - Try using ifort and gfortran 
! 1 -
! Running with last = 2   --> all ok
! 2 -
! Running with last = 10  --> all ok until i = 4, after crash ! (with the 
!    same operations that work until j = 4 ! )
! Use 
! valgrind --leak-check=full --show-reachable=yes ./a.out
! to find the problem 

  real a(10)
  integer i
  integer last
  integer dim
  real, allocatable :: myvett(:)


  dim = 25000000
  write(*,*) "Insert last "
  read(*,*) last

  do i=1, last
     allocate(myvett(dim))

     call set_val(a(1), dim, myvett);
  enddo

  write(*,*) "--> ", a(1)

end program



subroutine set_val(in, dim, myvett)

  implicit none

  real in
  integer dim
  real myvett(dim)
  integer i


  do i=1, dim
     myvett(i) = 7;
  enddo

  in = myvett(dim)

end subroutine
