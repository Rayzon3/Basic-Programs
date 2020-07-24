#include<stdio.h>
#include<stdlib.h>

int collatz(int n);

int main()
{
  int n;

  printf("Enter a number: ");
  scanf("%d", &n);

  printf(" %t The Collatz Conjecture Squence is: \n");

  collatz(n);

  return 0;
}


int collatz(int n)
{
  int nextTerm=n;

  printf("%d %t", n);

  // Base Case
  if(n==1)
  {
    return n;
  }
  //Collatz Conjecture Rule
  if(n%2==0)
  {
    nextTerm=n/2;
  }
  else if(n%2!=0)
  {
    nextTerm=(n*3)+1;
  }

  //Recursive Case
  return collatz(nextTerm);
}
