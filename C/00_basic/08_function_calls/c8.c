#include <math.h>
float quadrato (float);
float cubo_pos(float); 
float valore_assoluto(float);
/* -------------------------------------- *
 * Scrittura e compilazione di c8.c:      *
 * funzioni che chiamano funzioni che ... *
 * -------------------------------------- */
main ()
{
  float val1,tmp;

  /* leggi il dato */
  printf("Scrivi il float: ");
  scanf ("%f",&val1);
  tmp = val1;


  val1 = quadrato(val1);
  printf("Quadrato del numero: %f\n",val1);

  val1 = tmp;
  if (val1 <= 0.) {
    val1 = valore_assoluto(val1);
    printf("Valore assoluto: %f\n",val1);
  }

  val1 = tmp;
  val1 = cubo_pos(val1);
  printf("Cubo positivo del numero: %f\n",
	 val1);
    
}

/* ------------------------------------- */
float valore_assoluto(float x)
{
  if (x < 0.0)
    x = -x;

  return x;
}

/* ------------------------------------- */
float quadrato(float x)
{
  float y;
   
  y = x*x;

  return y;
}

/* ------------------------------------- */
float cubo_pos(float x)
{
  float tmp;
   
  tmp = x*x;
  if (x < 0.0) {
    x = -x;
    printf
      ("Funzione cubo_pos: cambio segno\n");
  }
  tmp *= x;

  return tmp;
}
