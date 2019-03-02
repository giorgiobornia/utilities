program test_oob

  implicit none

! Show Fortran problem of mismatch parameters when calling subroutines

  real a


  a = 0;

  call set_val(a, 100);

  write(*,*) "--> ", a
  write(*,*) "GOOD END"

end program



subroutine set_val(in, out)

  implicit none

  real in, out

  in = out

end subroutine
