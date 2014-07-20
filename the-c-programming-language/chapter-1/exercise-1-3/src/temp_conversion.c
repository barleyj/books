#include <stdio.h>

int main()
{

  float fahrenheit;
  float celsius;
  int start = 0;
  int end = 300;
  int step = 20;

  fahrenheit = start;

  printf ("Fahrenheit  Celsius\n");
  while(fahrenheit <= end) {
    celsius = (5.0/9.0) * (fahrenheit-32.0);
    printf ("%10.0f %8.1f\n", fahrenheit, celsius);
    fahrenheit =  fahrenheit + step;
  }

  return 0;
}
