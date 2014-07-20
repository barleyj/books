#include <stdio.h>

int main() {
  char character;
  int newLineCount = 0;
  int tabCount = 0;
  int blankCount = 0;

  while((character = getchar()) != EOF) {
    if(character == '\n') {
      newLineCount++;
    }
    if(character == '\t') {
      tabCount++;
    }
    if(character == ' ') {
      blankCount++;
    }
  }
  
  printf ("Blanks: %d\n", blankCount);
  printf ("Tabs: %d\n", tabCount);
  printf ("New Lines: %d\n", newLineCount);

  return 0;
}
