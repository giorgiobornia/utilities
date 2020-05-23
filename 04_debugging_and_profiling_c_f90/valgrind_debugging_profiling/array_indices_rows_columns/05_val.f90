!gfortran -O0 -Wall -g 05_val.f90 -o val
! valgrind ./val
! valgrind --log-file=valgrind.report ./val
! valgrind --leak-check=full --log-file=valgrind.report ./val
program val
	implicit none

integer :: i,j,k

integer ::l,m,n

real C,PI
real, allocatable    :: A(:,:,:), B(:,:)
!real :: B(10000,10000,10000) !,C(:,:,:)

l=100
m=100
n=100
allocate (A(l,m,n))
allocate (B(l,m))

	C=19.8981
	
	PI     = ABS(ACOS(-1.))
!allocate (C(l,m,n))

print *, "start"
do i=1,l
	do j=1,m
		do k=1,n
			C=PI*(i+j+k)*0.05
			B(i,j)=SIN(C)
			A(i,j,k) = B(i,j) 
!			A(k,j,i)= B(k,j,i) 
		enddo
	enddo
enddo

print *, "stop"
print *, "start"

do i=1,n
	do j=1,m
		do k=1,l
	
			B(k,j)= A(k,j,i) 
		
		enddo
	enddo
enddo
print *, "stop"
print *, "start"
call sbagliato(l,m,n)
print *, "stop"
print *, "start"
call giusto(l,m,n)
print *, "stop"
end


subroutine giusto (l,m,n)
implicit none

integer:: i,j,k,n,m,l

real A(l,m,n), B(l,m,n)

do i=1,n
	do j=1,m
		do k=1,l
	
			A(k,j,i)= B(k,j,i) 
		
		enddo
	enddo
enddo


end


subroutine sbagliato (l,m,n)
implicit none

integer:: i,j,k,n,m,l

real A(l,m,n), B(l,m,n)

do i=1,n
	do j=1,m
		do k=1,l
	
			A(i,j,k) = B(i,j,k)
		
		enddo
	enddo
enddo


end