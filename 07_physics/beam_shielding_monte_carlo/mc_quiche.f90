!Se si desidera stampare sullo standard output i dettagli della storia di ogni particella scommentare tutte le righe che iniziano con '!!!!'.

module contenitore
  real*8 s,en0,wn(6),w(6),a(6)
save
end module contenitore

module zatrix
  real*8 zatrixe(6,3,60000)
  real*8 zatrixs(6,3,60000)
save
end module zatrix

!INIZIO DEL PROGRAMMA
program mcquiche

use contenitore

  implicit none
  integer ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,nstart,nstorie,nult,nstorieass,i
  character*10 nomeel(6)
  character*10 anche
  character*8 conserva
  character*8 analyt
  logical analytic
  logical again
  integer maxncoll
  integer ce(20),cc(20),ceback(20),ccback(20)

  !PRESENTAZIONE DEL PROGRAMMA

  write(*,*) '*------------------------------------------------------------------*'
  write(*,*) '*-------------------------- MC QUICHE 3.14:------------------------*'
  write(*,*) '*------------------------------------------------------------------*'
  write(*,*) '*----- PROGRAMMA PER IL CALCOLO MONTECARLO DELLA TRASMITTANZA -----*' 
  write(*,*) '*-----DI UNA LASTRA DI CALCESTRUZZO DI COMPOSIZIONE VARIABILE------*'
  write(*,*) '*----------------IRRAGGIATA DA UN FASCIO NEUTRONICO----------------*'
  write(*,*) '*------------------MONODIREZIONALE E MONOCROMATICO-----------------*'
  write(*,*) '*------------------------------------------------------------------*'

  write(*,*) 'Benvenuto, caro utente.'

  !CHIAMATA DEI DATI DI INPUT
  CALL input()

  write (*,*) 'Desidera effettuare un puro confronto con la soluzione analitica, &
       & per accertarsi appieno della affidabilita del codice? s oppure n'
  read (*,'(A)')  analyt      !il formato è carattere

  do while ((analyt .ne. 's') .AND. (analyt .ne. 'n'))
     write(*,*) 'Cerchiamo di intenderci meglio... riprovi.'
     write(*,*) 'Vuole vedere se il codice ha un verso? s OPPURE n'
     read (*,'(A)')  analyt 
  end do

  if (analyt .eq. 's') then
     analytic = .true.
  elseif (analyt .eq. 'n') then
     analytic = .false.
     write(*,*) 'Bene, caro utente, Lei ha fiducia nel nostro prodotto.'
  endif

!qui inizia il ciclone

!inizializzo tutti i contatori...
          maxncoll = 0
          ntprimo = 0
          nt = 0
          nr = 0
          nass = 0
          nccum = 0
          nc = 0 !numero di particelle che ha superato il numero massimo di collisioni
          nct = 0 !numero di particelle che, se non avesse superato il numero massimo di collisioni, sarebbe stata trasmessa
          ncr = 0
          ncin = 0

!inizializzo i contatori dei file delle distribuzioni
  do i = 1, 20
   ce(i) = 0
   cc(i) = 0
   ceback(i) = 0
   ccback(i) = 0
  end do

!inizializzo il numero di storie
       nstart = 1
     write (*,'(''Inserisca gentilmente il numero di particelle da considerare:''$)') 
     read (*,*) nstorie
     nstorieass = nstorie
!inizializzo la variabile logica per le eventuali ripetizioni
  again = .true.

  trials: do while (again)

     CALL montecarlo(analytic,ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,maxncoll,nstart,nstorie,ce,cc,ceback,ccback)

     CALL output(analytic,ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,maxncoll,nstart,nstorie,nstorieass)

     write(*,*) 'Desidera seguire una nuova tornata di particelle? s oppure n'
     read(*,*) anche

     do while ((anche .ne. 's') .AND. (anche .ne. 'n'))
        write(*,*) 'Cerchiamo di intenderci meglio... riprovi.'
        write(*,*) 'Vuole lanciare altri neutroni? s OPPURE n'
        read(*,*) anche
     end do

     if (anche .eq. 's') then
           again  = .true.

           write(*,*) 'Vuole conservare le storie concluse finora? s oppure n'
           read(*,*) conserva

           do while ((conserva .ne. 's') .AND. (conserva .ne. 'n'))
                write(*,*) 'Cerchiamo di intenderci meglio... riprovi.'
                write(*,*) 'Vuole tenere da conto i calcoli conclusi? s OPPURE n'
                read(*,*) conserva
           end do

                  if (conserva .eq. 's') then
!riparto dal numero di storie concluse (quindi sottraggo quelle troncate)
                     nstart = nstorie - nc + 1
!non reinizializzo nessuna, a parte quelle troncate
                     maxncoll = 0 
                     nc = 0
                     nct = 0
                     ncr = 0
                     ncin = 0

    write (*,'(''Inserisca gentilmente il numero ulteriore di particelle da considerare:''$)') 
     read (*,*) nult
        nstorieass = nstorieass + nult
        nstorie = nstart + nult - 1

                  else if (conserva .eq. 'n') then
!reinizializzo tutti i contatori
                     maxncoll = 0
                     ntprimo = 0
                     nt = 0
                     nr = 0
                     nass = 0
                     nccum = 0
                     nc = 0 
                     nct = 0
                     ncr = 0
                     ncin = 0
!reinizializzo i contatori dei file delle distribuzioni
                     do i = 1, 20
                        ce(i) = 0
                        cc(i) = 0
                        ceback(i) = 0
                        ccback(i) = 0
                     end do
!reinizializzo il numero di storie
                     nstart = 1
                     write (*,'(''Inserisca gentilmente il numero di particelle da considerare:''$)') 
                     read (*,*) nstorie
                     nstorieass = nstorie
                 end if
 
     else if (anche .eq. 'n') then
        again  = .false.
        write(*,*) 'Bene, ha verificato la qualita del nostro prodotto, speriamo con successo!'

     end if

  end do trials

  write (*,*) '-------SALUTI # MC QUICHE 3.14------------'

end program mcquiche


!--------------------------SUBROUTINE MONTECARLO--------------------------

subroutine montecarlo(analytic,ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,maxncoll,nstart,nstorie,ce,cc,ceback,ccback)

use contenitore

  implicit none
  integer nstart,nstorie,maxcoll
  integer n,clock,i 
  integer ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin
  integer, allocatable :: seed(:)
  integer maxncoll
  integer j,z,l,m
  integer ce(20),cc(20),ceback(20),ccback(20)
  real*8 b,base,en,enout,r,mu0,mu,st,sa,ss,summ,thres
  real*8 eta1,eta2,eta3,eta4
  logical analytic
  character*10 nomeel(6)

    if (analytic .eqv. .false.) then
       write(*,*) 'Inserisca il numero massimo di collisioni per ogni particella (0 = primo volo):'
       read(*,*) maxcoll
           do while (maxcoll .lt. 0)
                write (*,*) 'Il numero di collisioni deve essere non negativo...riprovi.'
                write(*,*) 'Inserisca il numero massimo di collisioni per ogni particella (0 = primo volo):'
                read(*,*) maxcoll
           end do
    else 
      maxcoll = 7 !è un numero a caso, lo lascio così per vedere che il codice rimanga DA SOLO a j = 0 nel caso analitico
    end if

!inizializzazione generatore numeri casuali
  call random_seed(size = n)
  allocate (seed(n))
  call system_clock(count = clock)
  seed = clock + (/ (i-1, i = 1, n) /)
  call random_seed(put = seed)

!apriamo i file dei numeri casuali, accumulandoli con l'APPEND
!!!!  OPEN(11, FILE = 'eta1.dat', ACCESS = 'APPEND')
!!!!  OPEN(12, FILE = 'eta2.dat', ACCESS = 'APPEND')
!!!!  OPEN(13, FILE = 'eta3.dat', ACCESS = 'APPEND')
!!!!  OPEN(14, FILE = 'eta4.dat', ACCESS = 'APPEND')

!INIZIA IL CICLO SU CIASCUNA PARTICELLA
   write(*,*) '------SI APRANO LE DANZE---------'

  outer: do z = nstart,nstorie 

!!!!     write(*,*) '* ---Inizia la storia della particella', z
!inizializzo tutte le proprieta' della particella
     en = en0
     j = 0
     r = 0.d0
     mu = 1.d0
     mu0 = 1.d0

!!!!   write(*,*) 'Energia= ', en, 'eV'

!primo tentativo
     CALL random_number(eta1)
!!!!     WRITE(11,*) eta1

      m = 1  ! è l'indice delle sigma totali
     CALL sigmamacro(en,m,wn,st) ! ottengo la sigma MACROSCOPICA e TOTALE

     r = r + mu * (1.d0/st * Log(1.d0/eta1))
!questo r di primo tentativo e' certamente positivo

      inner: do while ( (j .le. maxcoll) .AND. (r .ge. 0.d0) .AND. (r .le. s) )

               call random_number(eta2)
!!!!               WRITE(12,*) eta2
!-------inizio ciclo scelta dell'elemento
               i = 0
               b = w(1)
               element: do 
                 i = i + 1
                 if (eta2.le.b) then
                    l = i !abbiamo trovato con quale elemento ha interagito
                    exit element
                    else
                    b = b + w(i+1)
                 endif
               end do element
!-------fine ciclo scelta dell'elemento

!----inizio ciclo scelta interazione
                m = 2   !è l'indice per l'assorbimento
                CALL sigmamicro(en,l,m,sa)

!!!!               write(*,*) 'elemento: ', nomeel(l)
!!!!               write(*,*) 'sa =', sa

               if (analytic) then
                   ss = 0.d0
                  else
                  m = 3  ! è l'indice per lo scattering 
                 CALL sigmamicro(en,l,m,ss)
               endif
!!!!               write(*,*) 'ss =', ss

              sa = sa + 1.d-9 !questo e' per evitare la divisione per zero, MALEDETTA!!!
              summ = sa + ss
              thres = sa/summ
              call random_number(eta3)
!!!!              WRITE(13,*) eta3
!--------------- inizio caso di assorbimento
                 if (eta3 .le. thres) then
                   exit inner 
!--------------- fine caso di assorbimento
                    else 
!--------------- inizio caso scattering ELASTICO
                    call random_number(eta4)
!!!!                    WRITE(14,*) eta4
                    base = eta4 / 5.d-1   !ipotesi di scattering isotropo nel sistema del centro di massa
                    mu0 = -1.d0 + base
                    mu = (a(l)*mu0 + 1.d0)/(dsqrt(a(l)**2 + 1.d0 + 2.d0*a(l)*mu0))
                    enout = en/((a(l) + 1.d0)**2)*((mu + (dsqrt((a(l))**2 - 1.d0 + mu**2)))**2)
                    en = enout
!aggiorniamo il valore di energia per la successiva collisione
!!!!                    write(*,*) 'Energia = ', en, 'eV'
!---------------fine caso scattering ELASTICO
                 endif
!---fine ciclo scelta interazione

           CALL random_number(eta1)
!!!!           WRITE(11,*) eta1
            m = 1 !è lindice delle sigma totali
            CALL sigmamacro(en,m,wn,st) ! ottengo la sigma MACROSCOPICA e TOTALE
            r = r + mu * (1.d0/st * Log(1.d0/eta1))
            j = j + 1
!qui aggiorniamo SIA r SIA j, quindi la condizione del while potrebbe non essere piu' verificata per due motivi contemporaneamente. Pertanto dopo dovremo distinguerli
         end do inner

!ora discriminiamo tutte le possibilita' di conteggio 
               if (j .gt. maxcoll) then
                   nc = nc + 1
!!!!                   write(*,*) 'Superato il limite massimo di collisioni: r/s = ', r/s
                           if (r/s .gt. 1.d0) then
                           nct = nct + 1
!!!!                           write (*,*) 'Sarebbe passata...'
                           else if (r/s .lt. 0.d0) then
                           ncr = ncr + 1
!!!!                           write (*,*) 'Sarebbe stata riflessa...'
                           else
                           ncin = ncin + 1
!!!!                           write (*,*) 'Avrebbe interagito dentro lo schermo...'
                           end if

               else if (r .gt. s) then
                                           if (j .eq. 0) then !distinguiamo j=0 dagli altri 
                                                  ntprimo = ntprimo + 1
!!!!                                                  write(*,*) 'La particella e stata trasmessa al primo volo: r/s =', r/s
                                           else
                                                  nt = nt + 1
!!!!                                                  write(*,*) 'La particella e stata trasmessa dopo la interazione #',j,':r/s =', r/s
                                          end if

!cicli per creare le distribuzioni di energia e angolo di uscita IN AVANTI
                        energie: do i = 1, 20  !suddividiamo in 20 canali le energie nell'intervallo [0,en0]
                             if ((en .gt. (REAL(20 - i)*en0)/20.d0) .AND. (en .le. (REAL(20 + 1 - i)*en0/20.d0))) then 
                                ce(20 + 1 - i) = ce(20 + 1 - i) + 1
                                exit energie
                             end if
                        end do energie

                        coseno:  do i = 1, 20 !suddividiamo in 20 canali i coseni nell'intervallo [0,1] (solo coseni positivi perche' le particelle escono IN AVANTI)
                              if ((mu .gt. (REAL(20 - i)/20.d0)) .AND. (mu .le. (REAL(20 + 1 - i)/20.d0))) then
                                cc(20 + 1 - i) = cc(20 + 1 -i) + 1
                                exit coseno 
                                end if
                        end do coseno
!effettuando i controlli a partire dai canali ad energia piu' alta e a coseno piu' alto e scrivendo EXIT risparmiamo tempo di calcolo

               else if (r .lt. 0.d0) then   !qui non serve distinguere tra i diversi j, sicuramente j è diverso da zero: per j=0 non posso avere r<o
                   nr = nr + 1
!!!!                   write (*,*) 'La particella e stata riflessa: r/s =', r/s

!cicli per creare le distribuzioni di energia e angolo di uscita ALL'INDIETRO
                        energiebk: do i = 1, 20  !suddividiamo in 20 canali le energie nell'intervallo [0,en0]
                             if ((en .gt. (REAL(20 - i)*en0)/20.d0) .AND. (en .le. (REAL(20 + 1 - i)*en0/20.d0))) then 
                                ceback(20 + 1 - i) = ceback(20 + 1 - i) + 1
                                exit energiebk
                             end if
                        end do energiebk

                        cosenobk:  do i = 1, 20 !suddividiamo in 20 canali i coseni nell'intervallo [-1,0] (solo coseni NEGATIVI perche' le particelle escono ALL'INDIETRO)
                              if ((mu .gt. (-i/20.d0)) .AND. (mu .le. (- i + 1)/20.d0)) then
                                ccback(20 + 1 - i) = ccback(20 + 1 -i) + 1
                                exit cosenobk 
                              end if
                        end do cosenobk

               else
                   nass = nass + 1
!!!!                   write(*,*) 'La particella e stata assorbita: r/s =', r/s
               endif

!!!!   write(*,*) '+ ---Termina la storia della particella', z,':j =', j

!cerco il massimo del numero di collisioni 
    if(j .gt. maxncoll) then
       maxncoll = j
    end if 

   end do outer
!accumulo il conteggio delle particelle troncate
   nccum = nccum + nc

!chiudiamo le unita' aperte in questa subroutine
!!!! CLOSE(11)
!!!! CLOSE(12) 
!!!! CLOSE(13)
!!!! CLOSE(14)

   write(*,*) '------STIAMO SCRIVENDO I FILE DI OUTPUT...---------'
!scriviamo i conteggi degli intervalli di energia e angolo d'uscita in due file
  OPEN(18, FILE = 'enout.out', STATUS = 'REPLACE')
  OPEN(19, FILE = 'muout.out', STATUS = 'REPLACE')
  OPEN(68, FILE = 'enoutback.out', STATUS = 'REPLACE')
  OPEN(69, FILE = 'muoutback.out', STATUS = 'REPLACE')
       do i = 1, 20
           WRITE(18,*) ce(i)
           WRITE(19,*) cc(i)
           WRITE(68,*) ceback(i)
           WRITE(69,*) ccback(i)
        end do
  CLOSE(18) 
  CLOSE(19)
  CLOSE(68) 
  CLOSE(69)

end subroutine montecarlo

!------------------------ SUBROUTINE DATI DI INPUT--------------------------------

subroutine input()

use contenitore
use zatrix

  implicit none

  real*8 Avo
  parameter(Avo = 6.022*10.d0**26)   ![# atomi/kmol] 
  integer ierr,i
  character*66 dummy1, dummy2
  character*40 nomefile
  character*10 nomecomp(5), nomeel(6)
  real*8 Vtot
  integer k,n,nlines(6,3),l,j,m
  real*8 ptot

  real*8 pip(60000), buffer(60000)
  integer ip(60000)
  real*8 pcomp(5),Ntot
  real*8 dens(5)
  data dens/3.94d3,3.37d3,5.2d3,2.2d3,5.7d3/   ! [kg/m^3]
  real*8 mmol(5)
  data mmol/102.d0,56.d0,160.d0,60.d0,123.d0/   ! [kg/kmol]


!vettore dei nomi dei composti del calcestruzzo
  nomecomp(1) = 'Al2O3'
  nomecomp(2) = 'CaO'
  nomecomp(3) = 'Fe2O3'
  nomecomp(4) = 'SiO2'
  nomecomp(5) = 'ZrO2'

!vettore dei nomi degli elementi!questi sono messi in ordine alfabetico
  nomeel(1) = 'Al'
  nomeel(2) = 'Ca'
  nomeel(3) = 'Fe'
  nomeel(4) = 'O'
  nomeel(5) = 'Si'
  nomeel(6) = 'Zr'

! a = vettore dei numeri di massa degli elementi
  a(1) = 27.d0
  a(2) = 40.d0
  a(3) = 56.d0
  a(4) = 16.d0
  a(5) = 28.d0
  a(6) = 91.d0
 
!inserimento utente dati geometrici (s), materiali (composizione) e fisici (en0)

  write (*,'(''Inserisca la energia [eV] dei neutroni incidenti, compresa fra 0 e 2e7 eV:''$)')
  read (*,*) en0
   do
     if (en0 .gt. 2.d7) then
      write (*,*) 'Neutroni troppo duri... riprovi.'
      write (*,'(''Inserisca la energia [eV] dei neutroni incidenti, compresa fra 0 e 2e7 eV:''$)')
      read (*,*) en0
     else if (en0 .lt. 0.d0) then
      write(*,*) 'Energie negative turbano la psiche... riprovi.'
      write (*,'(''Inserisca la energia [eV] dei neutroni incidenti, compresa fra 0 e 2e7 eV:''$)')
      read (*,*) en0
     else
       exit
     end if
   end do

  write (*,'(''Inserisca lo spessore della lastra [cm]:''$)')
  read (*,*) s

    ptot = 0.d0
    do k = 1,5
          write (*,*) 'Inserisca la percentuale in massa di ', nomecomp(k)
          read (*,*) pcomp(k)
          ptot = ptot + pcomp(k)
          write(*,*) 'Siamo al',ptot,'%'
    enddo

     do while (ptot .ne. 100.d0)

          write (*,*) 'Le percentuali non sono corrette... riprovi.'
 
       ptot = 0.d0
        do k = 1,5
              write (*,*) 'Inserisca la percentuale in massa di ', nomecomp(k)
              read (*,*) pcomp(k)
              ptot = ptot + pcomp(k)
              write(*,*) 'Siamo al',ptot,'%'
        enddo

     end do

!---conversione a partire dalle w_i (percentuali in massa) dei composti nelle N_j [#/barn*cm] degli elementi
 Vtot = 0.d0
  do k = 1,5
    Vtot = Vtot + (pcomp(k)/dens(k))
  enddo

  do j = 1,5
     wn(j)=((pcomp(j)/mmol(j))*Avo)/(Vtot*1.0d30)
  enddo
  ! wn = vettore delle densit di particelle per unit di volume dei 6 elementi
  wn(1) = 2.d0 * wn(1)
  wn(3) = 2.d0 * wn(3)
  wn(6) = wn(5)
  wn(5) = wn(4) 
  wn(4) = (3.d0/2.d0)*wn(1) + wn(2) + (3.d0/2.d0)*wn(3) + 2.d0*wn(5) + 2.d0*wn(6)


  Ntot = 0.d0
  do i = 1,6
     Ntot = Ntot + wn(i)
  enddo

  do i = 1,6
     w(i) = wn(i)/Ntot  !vettore delle densita' normalizzate a 1
  enddo
!------fine delle N [#/(barn*cm)]

!-----lettura dei file di dati e creazione delle matrici di sezioni d'urto e energie---------
! [sigma] = barn; [energia] = eV

  open (20, FILE = './input/Al_total.dat',STATUS = 'OLD')
  open (21, FILE = './input/Al_capture.dat',STATUS = 'OLD')
  open (22, FILE = './input/Al_elastic.dat',STATUS = 'OLD')
  open (23, FILE = './input/Ca_total.dat',STATUS = 'OLD')
  open (24, FILE = './input/Ca_capture.dat',STATUS = 'OLD')
  open (25, FILE = './input/Ca_elastic.dat',STATUS = 'OLD')
  open (26, FILE = './input/Fe_total.dat',STATUS = 'OLD')
  open (27, FILE = './input/Fe_capture.dat',STATUS = 'OLD')
  open (28, FILE = './input/Fe_elastic.dat',STATUS = 'OLD')
  open (29, FILE = './input/O_total.dat',STATUS = 'OLD')
  open (30, FILE = './input/O_capture.dat',STATUS = 'OLD')
  open (31, FILE = './input/O_elastic.dat',STATUS = 'OLD')
  open (32, FILE = './input/Si_total.dat',STATUS = 'OLD')
  open (33, FILE = './input/Si_capture.dat',STATUS = 'OLD')
  open (34, FILE = './input/Si_elastic.dat',STATUS = 'OLD')
  open (35, FILE = './input/Zr_total.dat',STATUS = 'OLD')
  open (36, FILE = './input/Zr_capture.dat',STATUS = 'OLD')
  open (37, FILE = './input/Zr_elastic.dat',STATUS = 'OLD')

  do l = 1,6
!l = 1: Al
!l = 2: Ca
!l = 3: Fe
!l = 4: O
!l = 5: Si
!l = 6: Zr
     do m = 1,3
!m = 1: interazione TOTALE
!m = 2: interazione di ASSORBIMENTO
!m = 3: interazione di SCATTERING
        read (20 + 3*(l-1) + m - 1,'(A)') dummy1
        read (20 + 3*(l-1) + m - 1,'(A)') dummy2
        ierr = 0
        i = 0
        do
           i = i + 1
           read(20 + 3*(l-1) + m - 1,'(6(f9.6,i2))',IOSTAT=ierr) (pip(6*(i-1)+j), ip(6*(i-1)+j),j = 1,6)
           if (ierr == -1) exit
        enddo
 
       nlines(l,m) = i-1

        do i = 1, nlines(l,m)*6
           buffer(i) = pip(i) * 10.d0**ip(i)
        enddo
        do n = 1, nlines(l,m)*3 
           Zatrixe(l,m,n) = buffer(2*(n-1) + 1)
           ZatrixS(l,m,n) = buffer(2*n)
        enddo

     enddo
  enddo

  return
end subroutine input



!---------------SUBROUTINE SIGMA MACROSCOPICA------------------------
subroutine sigmamacro(en,m,wn,sigmacro)

  implicit none
  integer l, m
  real*8 en,wn(6),smicro,sigmacro,sigmicro(6)

   sigmacro = 0.d0

  do l = 1,6
      CALL sigmamicro(en,l,m,smicro)
          sigmicro(l) = smicro
          sigmacro = sigmacro + sigmicro(l) * wn(l)
  end do

  return
end subroutine sigmamacro



!------------------SUBROUTINE SIGMA MICROSCOPICA----------------------
subroutine sigmamicro(en,l,m,smicro)

use zatrix

  implicit none
  integer n,nsup,l,m
  real*8 eps,en,deltaeup,deltaedown
  real*8 wn(6),smicro

!imponiamo una tolleranza, questa non ha senso chiederla all'utente, perche' noi conosciamo meglio di lui le tabelle dei dati che abbiamo a disposizione
  eps = 10.d0 ! tolleranza in eV

  n = 1 !inizializzo il contatore dell'energia

  do while (ZatrixE(l,m,n) .lt. en)
        n = n + 1
  enddo
  nsup = n
  if (nsup .gt. 1) then
     deltaeup = ZatrixE(l,m,nsup) - en
     deltaedown = en - ZatrixE(l,m,nsup-1)
     if (deltaeup .lt. eps) then
        smicro = Zatrixs(l,m,nsup)
     elseif (deltaedown .lt. eps) then
        smicro = Zatrixs(l,m,nsup-1)
     else 
        smicro = (deltaeup * Zatrixs(l,m,nsup-1) + deltaedown * Zatrixs(l,m,nsup)) / (deltaeup + deltaedown)
     endif
  else
     smicro = Zatrixs(l,m,nsup)
  endif

  return
end subroutine sigmamicro




!------------------SUBROUTINE OUTPUT---------------------------------------
subroutine output(analytic,ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,maxncoll,nstart,nstorie,nstorieass)

use contenitore

  implicit none
  integer ntprimo,nt,nass,nr,nccum,nc,nct,ncr,ncin,nstart,nstorie,j,m,nstorieass
  real*8 smacrotot,ct,cr,en,ctprimo,ctprimoan
  integer maxncoll
  logical analytic

  write(*,'(''RISULTATI DELLA SIMULAZIONE:'')')
  print *,'Numero totale di storie lanciate finora:' , nstorieass
  print *,'Numero totale di storie lanciate in questa tornata:' , nstorie - nstart + 1
  print *,'Numero di particelle *concluse* in questa tornata:', nstorie - nstart + 1 - nc
  print *,'Numero di particelle *troncate* in questa tornata:', nc
  print *,'          ...di queste:'
  print *,'            ', nct ,'sarebbero state trasmesse'
  print *,'            ', ncr ,'sarebbero state riflesse'
  print *,'            ', ncin ,'avrebbero interagito ancora dentro lo schermo'
  print *,'Saldo delle particelle *troncate*:', nct + ncr + ncin - nc
  print *,'Numero cumulato di particelle *troncate*', nccum
  print *,'Numero totale di particelle trasmesse al primo volo:' , ntprimo
  print *,'Numero totale di particelle trasmesse con diverse interazioni:' , nt
  print *,'Numero totale di particelle trasmesse:' , ntprimo + nt
  print *,'Numero totale di particelle assorbite:' , nass
  print *,'Numero totale di particelle riflesse:' , nr


!le due successive stampe servono all'utente per capire se proseguire con il numero di storie e di quanto aumentare il limite massimo alle collisioni 
  print *,'Rapporto tra le particelle troncate e le particelle totali in questa tornata:', REAL(nc)/REAL(nstorie - nstart + 1)
  if (nc .gt. 0) then  !AAA attenzione che nc puo' essere anche nullo, quindi puoi avere la divisione per zero!
  print *,'Rapporto tra le particelle troncate che avrebbero ancora interagito e il numero totale delle particelle troncate', & 
  & REAL(ncin)/REAL(nc)

  end if

  if (nc .gt. 0) then
  print *,'Numero massimo di collisioni per una particella', maxncoll - 1
  else
  print *,'Numero massimo di collisioni per una particella', maxncoll
  end if

  print *,'Saldo complessivo:', nt + ntprimo + nass + nr + nc - nstorie

  if (analytic .eqv. .false.) then
  ct = REAL(nt + ntprimo) / REAL(nstorie - nccum)  !NB: nel caso non analitico quelle troncate non le devo contare, perche' non spariscono dal fascio per motivi fisici, ma artificialmente ad opera dell'utente
  write(*,'(''Coefficiente di TRASMISSIONE calcolato con il metodo Montecarlo:'',f7.6)') ct
  cr = REAL(nr) / REAL(nstorie - nccum)
  write(*,'(''Coefficiente di RIFLESSIONE calcolato con il metodo Montecarlo:'',f7.6)') cr
  end if

  en = en0 !ricorda che nel caso analitico questa è sempre vera, altrimenti l'unico valore sensato di confronto è l'energia del fascio incidente en0. Quindi noi dobbiamo aggiornare en=en0, se non lo aggiornassimo avremmo come valore l'ultimo en dell'ultima particella simulata, che non è detto che sia = en0

  ctprimo = (REAL(ntprimo) / REAL(nstorie - nccum))
  write(*,*) 'Coeff. di TRASMISSIONE DI PRIMO VOLO calcolato con il metodo Montecarlo', ctprimo
  m = 1 !totale
  CALL sigmamacro(en,m,wn,smacrotot)
  write(*,*) 'Sezione di urto macroscopica totale [1/cm]', smacrotot
  ctprimoan = dexp(- smacrotot * s)
  write(*,*) 'Coeff. di TRASMISSIONE DI PRIMO VOLO calcolato analiticamente', ctprimoan
  write(*,*) 'Scostamento relativo del COEFF. DI TRASM. DI PRIMO VOLO rispetto al calcolo analitico:' , &
& 100.d0 * (ctprimo - ctprimoan)/ctprimoan ,'%'


! RICORDA che il fatto di mettere sigmascattering = 0 per il caso analitico equivale semplicemente a dire che OGNI PARTICELLA CHE INTERAGISCE E' RIMOSSA DAL FASCIO, ma questa "POSSIBILITA' DI INTERAZIONE" è calcolata invertendo la formula e^... dove c'è la SIGMA TOTALE, che quindi considera TUTTI i possibili fenomeni di interazione, anche lo scattering!
 
  return
end subroutine output

!-------------------------------APPENDICE A---------------------------

      !------------NUMERI DELLE UNITA' DI FORTRAN ASSOCIATE A CIASCUN FILE DI SEZIONI D'URTO------
      !    ----------total------capture-------elastic
      !     Al         20         21            22
      !     Ca         23         24            25
      !     Fe         26         27            28
      !     O          29         30            31 
      !     Si         32         33            34
      !     Zr         35         36            37

!-------------------------------APPENDICE B---------------------------

     !-------------RIASSUNTO DELLE PROPRIETA' DEI COMPOSTI DEL CALCESTRUZZO---------------------
     !--------Sostanza------------Densita'[kg/m^3-------Mmol [kg/kmol]
     !        Al2O3                3,94*10^3              102
     !        CaO                  3,37*10^3               56
     !        Fe2O3                5,2*10^3               160
     !        SiO2                 2,2*10^3                60
     !        ZrO2                 5,7*10^3               123 
