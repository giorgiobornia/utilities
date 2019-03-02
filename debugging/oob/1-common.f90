program test_oob

  implicit none

! Show the change of a variable value due to an out-of-bounds
! size(a) = size(b) = 10
! Run with last = 10 --> good results (a = 100, b = 200)
! Run with last = 11 --> good results (a = 100, b = 100) --> b(1) is 
!    changed in a mystery way !
! Compile with
! ifort test_oob1.f90 -O0 -g -check bounds
! to check oob

  real a(10), b(10)
  COMMON /mycomm/ a, b
  integer i
  integer last


  write(*,*) "Insert last "
  read(*,*) last

  do i=1, 10
     call set_val(b(i), 200.);
  enddo

  do i=1, last
     call set_val(a(i), 100.);
  enddo

  write(*,*) "--> ", a(1), b(1)

end program



subroutine set_val(in, out)

  implicit none

  real in, out

  in = out

end subroutine
