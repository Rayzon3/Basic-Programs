#include<stdio.h>
#include<stdlib.h>

int main()
{
  int x=3,y=6;

  printf("Before swapping: \n");
  printf("x = %d \n", x);
  printf("y = %d \n", y);

  x=x+y; // x=9
  y=x-y; // y=3
  x=x-y; // x=6

  printf("After swapping: \n");
  printf("x = %d \n", x);
  printf("y = %d \n", y);

  return 0;
}
