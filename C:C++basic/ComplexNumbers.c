#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int add(int a, int b, int x, int y);
int sub(int a, int b, int x, int y);
int multi(int a, int b, int x, int y);
int div(int a, int b, int x, int y);

int main()
{
  int a,b,x,y,c;

  printf("FOR FIRST COMPLEX NUMBER:\n");
  printf("Enter the real part of the complex number: \n");
  scanf("%d", &a);
  printf("Enter the imaginary part of the complex number: \n");
  scanf("%d", &b);

  printf("FOR SECOND COMPLEX NUMBER:\n");
  printf("Enter the real part of the complex number: \n");
  scanf("%d", &x);
  printf("Enter the imaginary part of the complex number: \n");
  scanf("%d", &y);

  printf("Choose from the following: \n");
  printf("1. Addition\n");
  printf("2. Subtration\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  scanf("%d", &c)

  if(c==1){
    add(a,b,x,y);
  }
  else if(c==2){
    sub(a,b,x,y);
  }
  else if(c==3){
    multi(a,b,x,y);
  }
  else if(c==4){
    div(a,b,x,y);
  }
  else{
    printf("Enter correct choice BAKA!! \n");
  }
  return 0;
}

int add(int a,int b,int x,int y)
{
  int p,q;

  p = a+x;
  q = b+y;

  return printf("The sum is %d + %di \n", p,q);
}

int sub(int a,int b,int x,int y)
{
  int p,q;

  p = a-x;
  q = b-y;

  return printf("The sum is %d + %di \n", p,q);
}

int multi(int a,int b,int x,int y)
{
  int p,q;

  p = (a*x) - (b*y);
  q = (a*y) + (b*x);

  return printf("The sum is %d + (%d)i \n", p,q);
}

int div(int a,int b,int x,int y)
{
  int p,q;

  p = ((a*x) + (b*y))/(pow(x,2) + pow(y,2));
  q = ((x*b) + (a*y))/(pow(x,2) + pow(y,2));

  return printf("The sum is %d + (%d)i \n", p,q);
}
