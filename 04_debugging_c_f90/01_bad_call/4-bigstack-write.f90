program test_oob

  implicit none

! Show problem with stack size and big automatic arrays
! Show gdb debug of core after show test_badcall4-3.f90

  real b(10)
  integer i


  do i=1, 10

     write(*,*) "Before set_val !"
     call set_val(b(i), 10000);

  enddo

  write(*,*) "--> ", b(1)

end program



subroutine set_val(in, dim)

  implicit none

  integer dim
  real in, out(dim*dim)


  write(*,*) "Inside set_val !"

  in = out(1) + out(dim)

end subroutine
