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
    int m,n,i,j,count=0;
    char s1[100000],s2[100000],ts[100000];
    scanf("%s",s1);
    scanf("%s",s2);
    m=strlen(s1);
    n=strlen(s2);
    strcpy(ts,s2);
    //printf("%s %d", s1,m);
    //printf("%s %d", s2,n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            if (s1[i]==s2[j] && s2[j]!='*')
            {
                count++;
                s2[j]='*';
                break;
            }
        }
    }
    for (i=0;i<n;i++)
    {  
        for (j=0;j<m;j++)
        {
            if (ts[i]==s1[j] && s1[j]!='^')
            {
                count++;
                s1[j]='^';
                break;
            }
                
        }
    }
    //printf("%d %d %d\n",m,n,count);
    printf("%d\n", (m+n-count));
}
