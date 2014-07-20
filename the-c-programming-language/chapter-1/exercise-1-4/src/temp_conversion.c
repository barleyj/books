#include <stdio.h>

int main()
{

  float fahrenheit;
  float celsius;
  int start = 0;
  int end = 300;
  int step = 20;

  celsius = start;

  printf ("Celsius  Fahrenheit\n");
  while(celsius <= end) {
    fahrenheit = ((celsius * 9.0) / 5.0) + 32.0;
    printf ("%7.0f %11.1f\n", celsius, fahrenheit);
    celsius =  celsius + step;
  }

  return 0;
}
