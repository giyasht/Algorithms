#include<stdio.h>
void main()
{
    int a,b,i,l=0;
    printf("enter 2 numbers\n");
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        for(i=2;i<=b;i++)
        {
            if(a%i==0 && b%i==0)
            {
                printf("gcd of %d and %d is %d",a,b,i);
                l++;
                break;
            }
        }
    }
    else if (b>a)
    {
        
        for(i=2;i<=a;i++)
        {
            if(a%i==0 && b%i==0)
            {
                printf("gcd of %d and %d is %d",a,b,i);
                l++;
                break;
            }
        }
    }
    if(l==0)
    {
        printf("gcd of %d and %d is 1",a,b);
    }
}
