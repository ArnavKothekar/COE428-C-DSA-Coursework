/* Copyright (C) 1999 Ken Clowes (kclowes@ee.ryerson.ca) */

static unsigned int numCompares = 0;
static unsigned int numSwaps = 0;
static unsigned int numCopies = 0;

int myCompare(int n1, int n2)
{
  numCompares++;
  return (n1 - n2);
}

void mySwap(int * ip1, int * ip2)
{
  int tmp;
  numSwaps++;
  tmp = *ip1;
  *ip1 = *ip2;
  *ip2 = tmp;
  return;
}

void myCopy(const int * ip1, int * ip2)
{
  numCopies++;
  *ip2 = *ip1;
  return;
}

unsigned int getNumCompares()
{
  return numCompares;
}

unsigned int getNumCopies()
{
  return numCopies;
}

unsigned int getNumSwaps()
{
  return numSwaps;
}

#ifdef TEST_METRICS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int main(){
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int nTests = 0;
  int tmp1, tmp2;
  
  /* Ensure that the initial counts are all zero. */
  assert(getNumSwaps() == 0); nTests++;
  assert(getNumCompares() == 0); nTests++;
  assert(getNumCopies() == 0); nTests++;

  /* Test compare operations */
  assert(myCompare(5, 5) == 0); nTests++;
  assert(myCompare(12, 34) < 0); nTests++;
  assert(myCompare(-5, -10) > 0); nTests++;
  assert(myCompare(0xffffffff, 0) < 0); nTests++;
  assert(getNumCompares() == 4); nTests++;

  /* Test swap operations */
  tmp1 = data[2];
  tmp2 = data[3];
  assert(tmp1 != tmp2);
  mySwap(&data[2], &data[3]);
  assert((tmp1 == data[3]) && (tmp2 == data[2])); nTests++;
  mySwap(&data[2], &data[3]);
  assert((tmp1 == data[2]) && (tmp2 == data[3])); nTests++;
  assert(getNumSwaps() == 2); nTests++;

  /* Test copy operations */
  myCopy(data+5, &tmp1);
  assert(tmp1 == 6); nTests++;
  assert(tmp1 != tmp2);
  myCopy(&tmp1, &tmp2);
  assert(tmp2 == 6); nTests++;
  assert(getNumCopies() == 2); nTests++;

  printf("The metrics module passed all %d tests\n", nTests);
  exit(0);
}
#endif /* TEST_METRICS */
