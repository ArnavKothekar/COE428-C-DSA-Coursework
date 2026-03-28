#include <stdio.h>
#include <stdlib.h>

static int top = 0;
static char * stack[100];

char *  pop(){
  if (top <= 0) {
    fprintf(stderr, "Stack empty\n");
    return (char *) 0;
  }
  return stack[--top];
}

void push(char * thing2push){
  if (top >= 100) {
    fprintf(stderr, "Stack full\n");
    return;
  }
  int len = 0;
  while (thing2push[len] != '\0') { len++; }
  char *newStr = (char *)malloc((len + 1) * sizeof(char));
  if (newStr != NULL) {
    int i;
    for (i = 0; i <= len; i++) {
	  newStr[i] = thing2push[i];
	}
	stack[top++] = newStr;
  }
}

int isEmpty(){
  return (top == 0);
}
