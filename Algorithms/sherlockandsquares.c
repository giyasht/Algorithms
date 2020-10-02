#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int t;
    scanf("%d",&t);
    while (t>0)
    {
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        float f=sqrt(a);
        long int p,count;
        p=(int)f;
        if (p==f)
        {
            count=((int)sqrt(b)-(int)sqrt(a) + 1);
        }
        else 
        {
            count=(int)sqrt(b)-(int)sqrt(a);
        }
        printf("%ld\n",count);
        t--;
    }
}
