#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern void addHeap(int);
extern int heapDelete();
extern int heapSize();
extern void printXML(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int value;
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
    addHeap(value);
  }
  
  printXML(0);
  printf("\n");

  while (heapSize() > 0) {
      int max = heapDelete();
      printf("%d\n", max);
      push(max);
  }

  while (!isEmpty()) {
      printf("%d\n", pop());
  }
  exit(0);
}
