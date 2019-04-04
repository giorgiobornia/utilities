

PROGRAM Marti

	!Determinazione del fattore moltiplicante e del flusso per interazione

      !Inserimento dei dati iniziali:
	!Le Sai,Sae indicano le sezioni d'urto d'assorbimento interne ed esterne rispettivamente
	!Le Sri,Sre indicano le sezioni d'urto di scatering out interne ed esterne rispettivamente
	!Il vettore X contiene numero medio di neutroni emessi 
	!	
	implicit none
	real*8 De, Di, Sai, Sae, Sri, Sre, B(6), C, qre, qri, qz, Xae, Xre, Xri
	real*8   ZA,E,F,G,H,O,Q,M1,M2,Pc,Pi,Pe,Uc,Ui,Ue,KOi,KOe,KOc
	real*8 SF11,SF21,K1,K2,I3,DELri,DELre,DELz
	integer  I,J,Z,L,N,I1,I2,KEY,RI,RE,HA
    integer M
    parameter (M=216)
	real*8   A(M,M),V(M),T(M),R(M),S(M,M),SF(6),W(6),X(M)
	data  W/2.6,2*2.4,2.6,2*2.4/
	data  SF/0.0015,0.0045,0.050,0.0016,0.0048,0.054/
	real*8 EK
	parameter (EK=0.0009)
	write(*,*) 'introduci raggio interno [cm] raggio esterno [cm] altezza [cm] del reattore'
	read(*,*) RI,RE,HA
	DELri=(RI/4)
	DELre=(RE-RI)/3
	DELz=HA/(2*8)
      
	

	!inserisco i valori iniziali di k e di sorgente che pongo come valore iniziale
	!di flusso
	
	K1=0.639
	do I=1,72
	    V(I)=(1/K1)*((2.6*0.0015+2.4*2*(0.0045+0.05))*0.6 +0.4*(2.6*0.0016+2.4*2*(0.0048+0.054)))
	end do
	do I=73,144
	   V(I)=0.061
	end do
	do I=145,216
	    V(I)=0.05
	end do
	!inizio programma con sudivisione in 3 gruppi
	I3=1
	do I=1,216
	   do J=1,216
		  A(I,J)=0
	      S(I,J)=0
	   end do
	end do
      I=1
	do L=1,3
	   if(L.EQ.1)THEN
	      De=1.71 
	      Di=1.71
	      Sai=0.0034
	      Sae=0.0035
	      Sri=0.061
	      Sre=0.061
	      
          else if(L.EQ.2)THEN
	      Di=0.85
	      De=0.85
	      Sai=0.023
	      Sae=0.024
	      Sri=0.05
	      Sre=0.05
	      
	    else if(L.EQ.3)then
	      Di=0.4
	      De=0.39
	      Sai=0.1
	      Sae=0.11
	      Sri=0.0
	      Sre=0.0
	      
	    end if
	    E=((2*Di)/(DELri**2)+2*Di/(DELz**2)+Sai+Sri)
	    Q=((2*De)/(DELre**2)+2*De/(DELz**2)+Sae+Sre)
	    F=-(Di/(DELri**2))
	    G=-(Di/(DELz**2))
	    O=-(De/(DELz**2))
	    H=-(De/(DELre**2))
		I1=I
    	    Z=1
		I3=0
	    call matrix1(Di,E,F,Sri,W,SF,L,A,I,M,S)
	    A(I,I+8)=2*G
	    do I=I1+Z,I1+Z+2
	      I3=I3+1
	      KEY=1
            call inter(E,F,Di,Sri,DELri,L,A,I,M,S,W,SF,KEY,I3)
  	      A(I,I+8)=2*G
	    end do
	    call bi(Di,De,Sai,Sae,Sri,Sre,DELri,DELre,DELz,W,SF,A,S,M,I,L) 
          A(I,I+8)=2*(G+O)
	    I3=4
	    do I=I1+Z+4,I1+Z+5
	     I3=I3+1
	     KEY=2
	     call inter(Q,H,De,Xre,qre,L,A,I,M,S,W,B,KEY,I3)
	     A(I,I+8)=2*O
	    end do
	    call contor(De,Xae,Xre,qre,qri,qz,L,A,I,M,S,W,B)
	    A(I,I+8)=2*O
	    I=I+1
	    I3=0

	!eseguo la mappatura della zona interna(riferito all'asse Z)

	    do Z=9,57,8
		  call matrix1(Di,E,F,Xri,W,B,L,A,I,M,S)
	      A(I,I+8)=G
	      A(I,I-8)=G
	      do I=I1+Z,I1+Z+2
	        I3=I3+1
	        KEY=1
              call inter(E,F,Di,Sri,DELri,L,A,I,M,S,W,SF,KEY,I3)
		    A(I,I+8)=G
	        A(I,I-8)=G
	      end do
	     call bi(Di,De,Sai,Sae,Sri,Sre,DELri,DELre,DELz,W,B,A,S,M,I,L) 
            A(I,I+8)=(G+O)
            A(I,I-8)=(G+O)
	      I3=4
	  	  do I=I1+Z+4,I1+Z+5
	        I3=I3+1
	        KEY=2
	        call inter(Q,H,De,Sre,DELre,L,A,I,M,S,W,SF,KEY,I3)
	        A(I,I+8)=O
	        A(I,I-8)=O
	      end do
            call contor(De,Sae,Sre,DELre,DELri,DELz,L,A,I,M,S,W,B)
		  A(I,I-8)=O
	      A(I,I+8)=O
	      I=I+1
	      I3=0
	    end do

	!definisco un pedice ZA che tiene conto della variazione lungo z
	      C=E+(1/DELz)
	      call matrix1(Di,ZA,F,DELri,W,SF,L,A,I,M,S)
	      A(I,I-8)=2*G
	    do I=I1+Z,I1+Z+2
	      I3=I3+1
	      KEY=1
            call inter(ZA,F,Di,Xri,qri,L,A,I,M,S,W,B,KEY,I3)
	      A(I,I-8)=2*G
	    end do
	    call bi(Di,De,Sai,Sae,Sri,Sre,DELri,DELre,DELz,W,SF,A,S,M,I,L) 
     	    A(I,I)=A(I,I)
          A(I,I-8)=(2*(G+O)+2/(qz**2))
	    I=I+1
	    I3=4
	    do I=I1+Z+4,I1+Z+5
	        ZA=Q+1/DELz
	        I3=I3+1
			KEY=2 
	        call inter(ZA,H,De,Sre,DELre,L,A,I,M,S,W,SF,KEY,I3)
  	        A(I,I-8)=2*O
	    end do
          call contor(De,Sae,Sre,DELre,DELri,qz,L,A,I,M,S,W,B)
	    A(I,I)=A(I,I)+1/DELz
	    A(I,I-8)=2*O
	    I=I1+Z+7
	PRINT *,'FINE PRIMO GRUPPO'
	PRINT '(I5,2X,I5,2X,I5)',I,Z,I1
	end do
	I2=1
	!determino i valori del vettore flusso "V" mediante interazione 
	PRINT *,'PRIMA INTERAZIONE'
      PRINT '(E15.8)',K1
	do I=1,72
	   R(I)=(10.d0**8)*(10.d0**9)
	end do
	do I=73,144
	   R(I)=8*(10.d0**7)*(10.d0**9)
	end do
	do I=145,216
	   R(I)=3*(10.d0**7)*(10.d0**9)
	end do
	go to 333

222   call prodmat(S,V,R,M)

333	do I=1,M
	     do N=1,M
	      if(N.NE.I)then
             T(I)=T(I)+A(I,N)*V(N)
	       end if
 	     end do
	end do

	do I=1,M
         V(I)=(1/(A(I,I))*(R(I)/K1-T(I)))
	end do

	! calcolo del fattore di moltiplicazione interato e del fattore di normalizzazione
      call prodmat(S,V,T,M)

      data Pc,Pi,Pe,Uc,Ui,Ue/6*0/
	do I1=1,145,72
	   if(I1.EQ.1)then
	      SF11=SF(1)
		  SF21=SF(4) 
	   else if(I1.EQ.73)then
	      SF11=SF(2)
		  SF21=SF(5) 
	   else
	      SF11=SF(3)
		  SF21=SF(6)
	   end if
	   do Z=1,65,8
	      do J=1,8
		     I=J+Z+I1-2
			 if(J.GE.1.AND.J.LT.5)then
			   KOi=KOi+T(I)*DELri*DELz
			   Ui=Ui+R(I)*DELri*DELz
			   Pi=Pi+V(I)*200*SF11*DELri*DELz
			 else if(J.EQ.5)then
			   Uc=Uc+R(I)*(DELri/2+DELre/2)*DELz
			   KOc=KOc+T(I)*(DELri/2+DELre/2)*DELz
			   Pc=Pc+V(I)*200*((SF11+SF21)/2)* (DELri/2+DELre/2)*DELz
	         else
			   KOe=KOe+T(I)*DELre*DELz
			   Ue=Ue+R(I)*DELre*DELz
			   Pe=Pe+V(I)*200*SF21*DELre*DELz
	         end if
             end do
	    end do
	end do

	K2=K1*((KOi+KOe+KOc)/(Ui+Ue+Uc))
      !uso T come termine di sorgente alla interazione successiva
	  PRINT *,'valore di k alla',I2,' iterazione'
	  PRINT '(F10.7)',K2

	M1=ABS((K2-K1)/K2)
	if(M1.GT.EK)then
	  I2=I2+1
	  K1=K2
	  go to 222
	end if
	!normalizzazione del flusso
	PRINT *,'  PRIMO GRUPPO'
	do I=1,72
	   V(I)=(800*(10.d0**9))/((Pe+Pi+Pc)*0.80219)*(10.d0**9)*(10.d0**3)*V(I)
	print '(e15.8)',v(I)
	end do
	PRINT *,'  SECONDO GRUPPO'
	do I=73,144
	 V(I)=(800*(10.d0**9))/((Pe+Pi+Pc)*1.60219)*(10.d0**9)*(10.d0**3)*V(I)
	print '(e15.8)',v(I)
	end do
	PRINT *,'   TERZO GRUPPO'
	do I=145,216
	   V(I)=(800*(10.d0**9))/((Pe+Pi+Pc)*1.60219)*(10.d0**9)*(10.d0**2)*V(I)
	print '(e15.8)',v(I)
	end do
	print *,'numero di iterazioni eseguite'
	print *,'n=',I2
	print *,'fattore di moltiplicita'
	print '(F10.8)',K2
	open(21,file="./output.out",status="new")
	do i=1,72
	  WRITE(21,*) V(I)
	end do
	do i=73,144
 	  WRITE(21,*) V(I)
	end do
	do i=145,216
 	  WRITE(21,*) V(I)
	end do

	END PROGRAM Marti


	       
	!subroutine del primo nodo

	subroutine matrix1(Di,E,F,Sr,W,SF,L,A,I,M,S)
	
	implicit none
	integer M
      real*8 A(M,M),S(M,M),W(6),SF(6)
	integer L,I
	real*8 E,F,Sr,Di
	A(I,I)=E+(2*Di/(19.d0**2))
	A(I,I+1)=4.d0*F
	if(L.EQ.1)then
	  S(I,I)=(W(1)*SF(1))
	  S(I,I+73)=(W(2)*SF(2))
	  S(I,I+145)=(W(3)*SF(3))
	end if
	if(L.EQ.1.OR.L.EQ.2)then
	  A(I+72,I)=-Sr
	end if
	RETURN
	end subroutine matrix1


      !subroutine della mappatura della regione interna

      subroutine inter(E,F,D,Sr,DELr,L,A,I,M,S,W,SF,KEY,I3)
                     
	
      real*8 A(M,M),S(M,M),W(6),SF(6)
	integer L,I,KEY
	real*8 E,F,W1,W2,W3,Sr,DELr,D,I3
	real*8 SF1,SF2,SF3
	if(KEY.EQ.1)then
	  W1=W(1)
	  W2=W(2)
	  W3=W(3)
	  SF1=SF(1)
	  SF2=SF(2)
	  SF3=SF(3)
	else if(KEY.EQ.2)then
	  W1=W(4)
	  W2=W(5)
	  W3=W(6)
	  SF1=SF(4)
	  SF2=SF(5)
	  SF3=SF(6)
	end if
      A(I,I)=E
	A(I,I+1)=F-D/(I3*(2*DELr**2))
	A(I,I-1)=F+D/(I3*(2*DELr**2))
	if(L.EQ.1)then
	  S(I,I)=(W1*SF1)
	  S(I,I+73)=(W2*SF2)
	  S(I,I+145)=(W3*SF3)
	end if
	if(L.EQ.1.OR.L.EQ.2)then
	   A(I+72,I)=-Sr      
	end if
	RETURN 
	end subroutine inter


      !subroutine del nodo di passaggio dalla regione interna a quella esterna

	   subroutine bi(Di,De,Sai,Sae,Sri,Sre,DELri,DELre,DELz,W,SF,A,S,M,I,L)
		  
	real*8 Di,De,Sai,Sae,Sri,Sre,DELri,DELre,DELz,A(M,M),S(M,M),W(6),SF(6)
	integer L,I
	real*8 qr
	real*8 q
	parameter (q=19.665)
	A(I,I)=(2*(Di+De)*(1/(DELz**2)+1/(q**2))+(Sai+Sae+Sri+Sre))
	A(I,I-1)=-(2*Di/(q**2))
	A(I,I+1)=-(2*De/(q**2))
	if(L.EQ.1)then
	  S(I,I)=((W(1)*SF(1))+(W(4)*SF(4)))
	  S(I,I+73)=((W(2)*SF(2))+(W(5)*SF(5)))
	  S(I,I+143)=((W(3)*SF(3))+(W(6)*SF(6)))
	end if
	if(L.EQ.1.OR.L.EQ.2)then
	   A(I+72,I)=-(Sri+Sre)      
      end if
	return
	end subroutine bi 


	!subroutine del nodo posto sulcontorno esterno

	    subroutine contor(D,Sa,Sr,DELre,DELri,DELz,L,A,I,M,S,W,SF)

	real*8 Sa,Sr,DELre,DELri,DELz,A(M,M),S(M,M),W(6),SF(6)
	integer L,I
	real*8 D 
	A(I,I)=((2*D)*(1/(DELre**2)+1/(DELz**2))+Sa+Sr+1/DELre+1/(2*(DELri*4+DELre*3)))
	A(I,I-1)=-(2*D/(DELre**2))
	if(L.EQ.1)then
        S(I,I)=(W(4)*SF(4))
	  S(I,I+72)=(W(5)*SF(5))
	  S(I,I+143)=(W(6)*SF(6))
	end if
	if(L.EQ.1.OR.L.EQ.2)then
	    A(I+72,I)=-Sr    
	end if
	return 
	end subroutine contor

        subroutine prodmat(S,V,R,M)

      integer I,L,M
	real*8 S(M,M),V(M),R(M)
  	do I=1,M
	    R(I)=0
	       do L=1,M
	        R(I)=R(I)+S(I,L)*V(L)
	       end do
	end do
	return
	end subroutine prodmat
