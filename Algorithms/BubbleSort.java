import java.util.Scanner;

public class BubbleSort {
    public static void swap(int[] arr ,int a,int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void bubbleSort(int []arr)
    {
        int length = arr.length;
        for (int i = 0; i < length - 1; i++)
        {
            int swaps =0;
            for (int j = 0; j < length - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr,j,j+1);
                    swaps++;
                }
            }
            if(swaps==0)
            {
                break;
            }
        }
    }
    public static void printArray(int []arr)
    {
        for (int i :arr)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter number of elements you want to insert in the array");
        int n = scan.nextInt();
        int []arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = scan.nextInt();
        }

        bubbleSort(arr);
        System.out.println("Sorted array");
        printArray(arr);
    }
}
