
  /* Do-while is performed at least once */

int main ()
{
  int in,digit,tmp;
  int out = 0;

  printf("Enter your number: ");
  scanf("%d",&in);

  tmp = in;
  do {
    digit = in%10;
    out = out*10 + digit;
    in /= 10;
  } while (in != 0);

  printf("%d \n",out);

  /* una piccola variazione */ 
  in = tmp;
  do {
    digit = in%10;
    printf("%d",digit);
    in = in/10;
  } while (in != 0);

  printf("\n");
}



/*
raus@birillo --> ./c5b
Enter your number: 2347
7432
7432
raus@birillo -->

variabile in: 
si suppone che sia un intero >=0
(bisognerebbe essere sicuri di non mettere 
niente altro che cifre!)

Abbiamo usato il ciclo do {...} while, 
perche' il dato in = 0 e' valido, quindi 
deve fare almeno un ciclo prima di uscire.*/
