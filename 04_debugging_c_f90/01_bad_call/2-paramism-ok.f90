program test_oob

  implicit none

! Show Fortran problem of mismatch parameters when calling subroutines
! Pay attention to correctly give parameters to the subs

  real a
  real par
  par = 100

  
  a = 0;
  call set_val(a, par);
  write(*,*) "--> ", a

! OR ( WORSE )

  a = 0;
  call set_val(a, 100.);
  write(*,*) "--> ", a

  write(*,*) "GOOD END"

end program



subroutine set_val(in, out)

  implicit none

  real in, out

  in = out

end subroutine
