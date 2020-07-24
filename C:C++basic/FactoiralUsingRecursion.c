#include<stdio.h>
#include<stdlib.h>

int fact(int n);


int main()
{
  int n;

  printf("Enter a number: \n");
  scanf("%d", &n);

  return printf("%d! = %d \n", n,fact(n));
}

int fact(int n)
{
  // Assuming the user inputs +ve integer or 0
  if(n>=1)
  {
    return n*fact(n-1);  //Recursion
  }
  else
  {
    return 1;
  }
}
