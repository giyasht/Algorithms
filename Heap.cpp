// IMPLEMENTING HEAP DATA STRUCTURE FROM SCRACH

#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    // INSERTING ELEMENT IN HEAP

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // DELETING ELEMENT FROM HEAP

    void deleteheap()
    {
        if (size == 0)
        {
            cout << "khali he heap b#@K" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int l = 2 * i;
            int r = 2 * i + 1;
            if (l < size && arr[l] > arr[i])
            {
                swap(arr[l], arr[i]);
                i = l;
            }
            else if (r < size && arr[r] > arr[i])
            {
                swap(arr[r], arr[i]);
                i = r;
            }
            else
                return;
        }
    }

    // PRINTING HEAP ELEMENTS

    void print()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l < n && arr[l] > arr[i])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[i])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// DRIVER CODE

int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.print();
    h.deleteheap();
    h.print();
    int arr[11] = {-1, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int n = 11;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}