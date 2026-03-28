#include <stdio.h>
#include <stdlib.h>

static int top = 0;
static int stack[100];

int pop(){
  if (top <= 0) {
      fprintf(stderr, "Stack empty\n");
      return -1;
  }
  return stack[--top];
}

void push(int thing2push){
  if (top >= 100) {
	fprintf(stderr, "Stack full\n");
    return;
  }
  stack[top++] = thing2push;
}

int isEmpty(){
  return (top == 0);
}
