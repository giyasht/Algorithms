import java.util.*;
public class Algo_0_1Knapsack
{
    public static void main(String args[])
    {
        System.out.println( "01 KNAPSACK");
        Scanner sc= new Scanner(System.in);
        int n,W;
        System.out.println("Enter the total capacity of the Knapsack : ");
        W=sc.nextInt();
        System.out.println("Enter the number of different elements present : ");
        n=sc.nextInt();
        int wt[]= new int[n];
        int val[]= new int[n];
        
        System.out.println("Enter the weights of the elements");
        for (int i =0; i<n; i++)
        {
            wt[i]=sc.nextInt();
        }
        System.out.println("Enter the price of the elements");
        for (int i =0; i<n; i++)
        {
            val[i]=sc.nextInt();
        }
        int max= knapsack(wt,val, n,W);
        System.out.println("The maximum profit of the knapsack is : " + max);
    }
    public static int knapsack(int wt[], int val[], int n, int W)
    { 
        int t[][]= new int[n+1][W+1];
        for (int i = 0; i <= n; i++)  
        { 
            for (int j = 0; j <= W; j++)  
            {     
                if (i==0 || j==0)
                    t[i][j]= 0;
                else if (wt[i-1] <= j) 
                    t[i][j]=Math.max((val[i-1]+ t[i-1][j-wt[i-1]]),t[i-1][j]);    
                else 
                    t[i][j]= t[i-1][j];
            }
        }
        return t[n][W];
    }
}
