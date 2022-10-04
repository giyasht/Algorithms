#include <stdio.h>
#include <stdlib.h>

//===================================================Question1============================================
int front = -1;
int tail = -1;
int queue[100];
int length_queue;

int peekqueue()
{
    return queue[front];
}

void enQueue(int n)
{
    if (tail == length_queue - 1 && front == 0)
    {
        printf("Queue overflow\n");
    }
    else if (tail + 1 == front && tail != -1)
    {
        printf("Queue Overflow\n");
    }
    else if (front == -1 && tail == -1)
    {
        front = tail = 0;
        queue[front] = n;
    }
    else if (tail == length_queue - 1)
    { // max length -1
        tail = (tail + 1) % length_queue;
        queue[tail] = n;
    }
    else
    {
        queue[++tail] = n;
    }
}

int deQueue()
{
    if (front == -1 && tail == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else if (front == length_queue - 1 && tail != 0)
    { // maxlen-1
        int val = queue[front];
        front = (front + 1) % length_queue;
        return val;
    }
    else if (front == tail && front != -1)
    {
        int val = queue[front];
        front = tail = -1;
        return val;
    }
    else
    {
        return queue[front++];
    }
}

void display()
{

    if (front == -1 && tail == -1)
    {
        printf("Nothing to display, queue is empty!\n");
        return;
    }
    if (front <= tail)
    {
        for (int i = front; i <= tail; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < length_queue; i++)
        {
            printf("%d ", queue[i]);
        }
        for (int j = 0; j <= tail; j++)
        {
            printf("%d ", queue[j]);
        }
    }
    printf("\n%d %d\n", front, tail);
}

int pairs_count()
{
    int count = 0;
    for (int i = 0; i < length_queue; i++)
    {
        int val = deQueue();
        if (val - peekqueue() == 1 || peekqueue() - val == 1)
        {
            count++;
            printf("( %d , %d ) ", val, peekqueue());
        }
        enQueue(val);
    }
    return count;
}

void Q1()
{
    printf("\n Enter the size of the queue: ");

    scanf("%d", &length_queue);

    for (int i = 0; i < length_queue; i++)
    {
        printf("ENter the %d element: ", i + 1);
        int num;
        scanf("%d", &num);
        enQueue(num);
    }
    printf("Your queue made is : ");
    display();
    printf("\n");

    int cc = pairs_count();
    printf("\nTotal no of pairs are %d \n\n\n", cc);
}

//=================================Question2=====================================================

void Q2()
{
    printf("Program : 2\n\n");
    printf("Enter The size of the Array To Be Traversed : ");
    int size_01;
    scanf("%d", &size_01);

    int arr[size_01];
    printf("\nEnter The Elements in The Array : ");
    for (int i = 0; i < size_01; i++)
        scanf("%d", &arr[i]);

    printf("\nEnter The Key To Be Searched : ");
    int key;
    scanf("%d", &key);

    int count_01 = 0;

    for (int i = 0; i < size_01; i++)
    {
        if (arr[i] == key)
            count_01++;
    }

    if (count_01 == 0)
        printf("The Key is not Present Anywhere in the Array\n");

    else
    {
        int index_01[count_01];
        int j = 0;

        for (int i = 0; i < size_01; i++)
        {
            if (arr[i] == key)
            {
                index_01[j] = i;
                j++;
            }
        }

        printf("\nThe Key has been Repeated %d number of Times\n", count_01);
        printf("\nThe Indexes will be Present at: (");
        for (int i = 0; i < count_01 - 1; i++)
            printf("%d, ", index_01[i]);
        printf("%d)\n", index_01[count_01 - 1]);
    }
}

//=================================================Question 3------=-================================================================================
int binarySearchForLab(int arrayOfNumbers[], int keyToSearch, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arrayOfNumbers[mid] * arrayOfNumbers[mid] == keyToSearch)
        {
            return mid;
        }
        if (arrayOfNumbers[mid] * arrayOfNumbers[mid] < keyToSearch)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void Q3()
{
    int inputNumber;
    printf("Enter the number to check if it is a prefect square[make sure the number is below 144]: ");
    scanf("%d", &inputNumber);
    int perfectSquareNumbers[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int searchResult = binarySearchForLab(perfectSquareNumbers, inputNumber, 0, 11);
    if (searchResult == -1)
    {
        printf("The number you have input[%d] is not a perfect square.\n", inputNumber);
        return;
    }
    printf("The input number[%d] is a perfect square of %d\n", inputNumber, searchResult + 1);
}

//===============================================================================question 4===============================================
void binary_search(int bin_Array[], int element, int size)
{
    int start = 0, end = size, centre;
    int loop = 0;
    while (start <= end)
    {
        centre = (start + end) / 2;

        if (bin_Array[centre] == element)
        {
            printf("\nFound the Element and it is on index : %d\nThe Program did %d many Comparisons.\n", centre + 1,loop);
            return;
        }

        else if (bin_Array[centre] < element)
            start = centre + 1;
        else
            end = centre - 1;
        loop++;
    }

    if (centre == size)
        printf("The Element is Not Present and Key is The Greatest Number in the Number\n");
    else
        printf("The Greater Element would be : %d at Index : %d\nThe Program did %d many Comparisons.\n", bin_Array[centre + 1], centre + 1, loop);
}

void Q4()
{
    printf("Enter The Size of The Array  : ");
    int size_04;
    scanf("%d", &size_04);

    int arr_04[size_04];
    printf("\nEnter the Elements in the Array: ");
    for (int i = 0; i < size_04; i++)
        scanf("%d", &arr_04[i]);

    printf("\nEnter Element to be Found : ");
    int element;
    scanf("%d", &element);

    binary_search(arr_04, element, size_04);
}
int main()
{
    Q1();
    Q2();
    Q3();
    Q4();
    return 0;
}
