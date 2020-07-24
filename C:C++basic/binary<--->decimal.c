#include <stdio.h>
#include <math.h>
int convertBinaryToDecimal(long long n);
long long convertDecimalToBinary(long long n);
int main()
{
    int x;
    long long n;

    printf("Choose from the following: \n");
    printf("1.Binary ----> Decimal \n");
    printf("2.Decimal ----> Binary \n");
    scanf("%d", &x);
    switch (x) {
        case 1:
             printf("Enter a binary number: \n");
               scanf("%lld", &n);
               printf("%lld in binary = %d in decimal.\n", n,convertBinaryToDecimal(n));
            break;
        case 2:
            printf("Enter a decimal number: \n");
               scanf("%lld", &n);
            printf("%lld in decimal = %lld in binary. \n", n,convertDecimalToBinary(n));
            break;

        default:printf("Enter correct choice BAKA!! \n");
            break;
    }


    return 0;
}

int convertBinaryToDecimal(long long n)
{
    int binaryNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        binaryNumber += remainder*pow(2,i);
        ++i;
    }
    return binaryNumber;
}

long long convertDecimalToBinary(long long n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
    while (n!=0)
    {
        remainder = n%2;
        printf("Step %d: %lld/2, Remainder = %d, Quotient = %lld\n", step++, n, remainder,n/2);
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }

    return binaryNumber;
}
