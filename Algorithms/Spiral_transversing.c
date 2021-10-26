#include<stdio.h>

int main()
{
int arr[6][6] = {1, 2,3,4,5,6,
                 7,8,9,10,11,12,
				 13,14,15,16,17,18,
                 18,17,16,15,14,13,
				 12,11,10,9,8,7,
				 6,5,4,3,2,1};
				 
				 int i;
				 int minr;
				 int minc;
			     int maxr;
				 int maxc;
				 minr=0;
				 minc=0;
				 maxr=5;
				 maxc=5;
				 
		for(i=minr; i<= maxr; i++)
		{
			printf("%d\n", arr[i][minc]);
				   }
				   minc++;
				   
		for(i=minc; i<=maxc; i++)
		{
			printf("%d\n", arr[maxr][i]);
							  }	
							  maxr--;
							  
		for(i=maxr; i>= minr; i--)
		{
			printf("%d\n", arr[i][maxc]);
							}	
							maxc--;
							
		for(i=maxc; i>=minc; i--)
		{
			printf("%d\n", arr[minr][i]);
				}		
				minr++;		
				
				 minr=1;
				 minc=1;
				 maxr=4;
				 maxc=4;
				 
				 		for(i=minr; i<= maxr; i++)
		{
			printf("%d\n", arr[i][minc]);
				   }
				   minc++;
				   
		for(i=minc; i<=maxc; i++)
		{
			printf("%d\n", arr[maxr][i]);
							  }	
							  maxr--;
							  
		for(i=maxr; i>= minr; i--)
		{
			printf("%d\n", arr[i][maxc]);
							}	
							maxc--;
							
		for(i=maxc; i>=minc; i--)
		{
			printf("%d\n", arr[minr][i]);
				}		
				minr++;	
				
				
				 minr=2;
				 minc=2;
				 maxr=3;
				 maxc=3;
				 
				 for(i=minr; i<= maxr; i++)
		{
			printf("%d\n", arr[i][minc]);
				   }
				   minc++;
				   
		for(i=minc; i<=maxc; i++)
		{
			printf("%d\n", arr[maxr][i]);
							  }	
							  maxr--;
							  
		for(i=maxr; i>= minr; i--)
		{
			printf("%d\n", arr[i][maxc]);
							}	
							maxc--;
							
		for(i=maxc; i>=minc; i--)
		{
			printf("%d\n", arr[minr][i]);
				}		
				minr++;		
				 
				 					  	   		   
}
