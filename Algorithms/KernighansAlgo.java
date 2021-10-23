/*
Brian Kernighan's Algorithm

Problem Statement : Find the number of 1s in the Binary Equivalent of a number.
Sample Input : 76
Sample Output : 3
Explanation : The binary equivalent of 76 is 1001100 
              Thus the number of Set bits (or 1s) is 3
 */
import java.util.*;
public class KernighansAlgo 
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number : ");
        int n=sc.nextInt();
        int copy=n;
        int count = 0;
        while(n!=0)
        {
            int rmsb = n&-n;
            n=n-rmsb;
            count++;        
        }
        System.out.println("The number of 1s in the Binary Equivalent of "+copy +" is : "+count);
    }
}
