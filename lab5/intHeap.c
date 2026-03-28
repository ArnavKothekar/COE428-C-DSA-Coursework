#include <stdio.h>
#include <stdlib.h>

static int heap[100];
static int size = 0;

int heapDelete(){
  if (size <= 0) return -1;
  int max = heap[0];
  heap[0] = heap[--size];
  
  int i = 0;
  while (2 * i + 1 < size) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int largest = i;

      if (left < size && heap[left] > heap[largest]) largest = left;
      if (right < size && heap[right] > heap[largest]) largest = right;

      if (largest != i) {
          int temp = heap[i];
          heap[i] = heap[largest];
          heap[largest] = temp;
          i = largest;
      } else {
          break;
      }
  }
  return max;
}

void addHeap(int thing2add){
  int i = size++;
  heap[i] = thing2add;
  
  while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
      int temp = heap[i];
      heap[i] = heap[(i - 1) / 2];
      heap[(i - 1) / 2] = temp;
      i = (i - 1) / 2;
  }
}

int heapSize(){
  return size;
}

void printXML(int index){
    if (index >= size) return;
    printf("<node id=\"%d\">", heap[index]);
    printXML(2 * index + 1);
    printXML(2 * index + 2);
    printf("</node>");
}
