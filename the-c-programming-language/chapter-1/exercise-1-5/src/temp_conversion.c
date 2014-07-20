#include <stdio.h>

int main()
{

  float fahrenheit;
  float celsius;
  int start = 300;
  int end = 0;
  int step = 20;

  fahrenheit = start;

  printf ("Fahrenheit  Celsius\n");
  for (fahrenheit = start; fahrenheit >= end; fahrenheit -= step){
    celsius = (5.0/9.0) * (fahrenheit-32.0);
    printf ("%10.0f %8.1f\n", fahrenheit, celsius);
  }

  return 0;
}
