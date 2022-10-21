#include<stdio.h>
#include<conio.h>
int main()
{
    int year;
    printf("Enter Year: ");
    scanf("%d", &year);
    if((year%4==0) && (year%100!=0))
        printf("\nIt's a Leap Year");
    else if(year%400==0)
        printf("\nIt's a Leap Year");
    else
        printf("\nIt's not a Leap Year");
    getch();
    return 0;
}
