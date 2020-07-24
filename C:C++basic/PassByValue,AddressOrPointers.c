#include<stdio.h>
#include<stdlib.h>

void passByValue(int x, int y);
void passByReference(int &x, int &y);
void passbyAddress(int *x, int *y);

int main(){

  int a = 3;
  int b = 4;

  printf("Values before swapping: \n");
  printf("a = %d \n", a);
  printf("b = %d \n", b);

  printf("Values after swapping: \n");

  passByValue(a,b);
  printf("Pass by value:- \n");
  printf("a = %d \n", a);
  printf("b = %d \n", b);

  passByReference(a,b);
  printf("Pass by reference:- \n");
  printf("a = %d \n", a);
  printf("b = %d \n", b);

  passbyAddress(&a, &b);
  printf("Pass by address:- \n");
  printf("a = %d \n", a);
  printf("b = %d \n", b);

return 0;
}

void passByValue(int x, int y){
  int t;

  t = x;
  x = y;
  y = t;
}

void passByReference(int &x, int &y){
  int t;

  t = x;
  x = y;
  y = t;
}

void passbyAddress(int *x, int *y){
  int t;

  t = *x;
  *x = *y;
  *y = t;
}
