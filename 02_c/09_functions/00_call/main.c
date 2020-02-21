#include <math.h>

float square (float);
float cube_pos(float); 
float absolute_value(float);


main ()
{
  float val1,tmp;

  /* leggi il dato */
  printf("Write the number: ");
  scanf ("%f",&val1);
  tmp = val1;


  val1 = square(val1);
  printf("Square: %f\n",val1);

  val1 = tmp;
  if (val1 <= 0.) {
    val1 = absolute_value(val1);
    printf("Absolute value: %f\n",val1);
  }

  val1 = tmp;
  val1 = cube_pos(val1);
  printf("Positive cube: %f\n",
	 val1);
    
}

/* ------------------------------------- */
float absolute_value(float x)
{
  if (x < 0.0)
    x = -x;

  return x;
}

/* ------------------------------------- */
float square(float x)
{
  float y;
   
  y = x*x;

  return y;
}

/* ------------------------------------- */
float cube_pos(float x)
{
  float tmp;
   
  tmp = x*x;
  if (x < 0.0) {
    x = -x;
    printf
      ("cube_pos: change of sign \n");
  }
  tmp *= x;

  return tmp;
}
