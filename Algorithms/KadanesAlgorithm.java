/*
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Sample Input : nums = [-2,1,-3,4,-1,2,1,-5,4]
Sample Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Sample Input : nums = [5,4,-1,7,8]
Sample Output: 23
*/

// Kadane's Algorithm has been used to solve this problem.

import java.util.*;
public class KadanesAlgorithm 
{
    public static int maxSubArray(int[] nums) 
    {
        int max_so_far=-999999;
        int curr_sum=0;
        for(int i=0;i<nums.length;i++)
        {
            curr_sum+=nums[i];
            if(curr_sum>max_so_far)
                max_so_far =curr_sum;    
            if (curr_sum<0)
                curr_sum=0;     
        }
        return max_so_far;
    }
    public static void main(String args[])
    {
	Scanner sc= new Scanner(System.in);
	System.out.print("Enter the Size of array : ");
	int l= sc.nextInt();
	int arr[]=new int[l];
	System.out.println("Enter the array elements");
	for (int i=0; i<l;i++)
	{
	    arr[i]=sc.nextInt();
	}
        int sum= maxSubArray(arr);
        System.out.println("The largest possible sum of contiguous subarray : " + sum);
    }
}
