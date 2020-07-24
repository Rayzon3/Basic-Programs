#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char a[50], b[50];
  int x, y, i, r=0;

  printf("Enter first string : \n");
  gets(a);
  printf("Enter second string : \n");
  gets(b);

  x = strlen(a);

  for(i=x+1; i<=50; i++)
  {
    a[i]=b[r];
    r++;
  }

  for(i=0; i<=50; i++)
  {
    printf("%c",a[i]);
  }

return 0;
}
