#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define IS_SPACE(c) c ^ ' '

int main() {
  char c;
  int isDeDupe = FALSE;

  while((c = getchar()) != EOF) {
    if(c == ' ' && !isDeDupe) {
      continue;
    }

    putchar(c);
    isDeDupe = IS_SPACE(c);
  }
  
  return 0;
}
