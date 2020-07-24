#include<stdio.h>
#include<stdlib.h>

int main()

{
  int n;

  printf("Enter the number of prime numbers you want. \n");
  scanf("%d", &n);

  printf("\t The following are the first %d prime numbers: \t \n", n);

  for(int x=1;x<=n;x++)
  {
    if(x%2==0||x%3==0||x%5==0||x%7==0||x%11==0)
    {
      if(x==2||x==3||x==5||x==7||x==11)
      {
        printf("%d\n", x);
      }
    }
    else if(x%2!=0||x%3!=0||x%5!=0||x%7!=0||x%11!=0)
     {
       printf("%d\n", x);
     }

  }
  return 0;
}
