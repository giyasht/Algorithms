#include <bits/stdc++.h>
using namespace std;

struct Kstack
{
    int *arr, *next, *top;
    int k, freeSpot, cap;

    // constructor
    Kstack(int n, int k1)
    {
        k = k1;
        // k is number of stacks
        // n is size of arr
        cap = n;
        freeSpot = 0;
        arr = new int[cap];
        next = new int[cap];
        top = new int[k];
        for (int i = 0; i < k; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < cap - 1; i++)
        {
            next[i] = i + 1;
        }
        next[cap - 1] = -1;
        // Intially next store the next space
        // And after addition of element it update to previous value;
    }

    // ---- push ----- // operation
    void push(int x, int sn)
    {
        // sn is stack number from 0 to k-1;
        if (freeSpot == -1)
        {
            cout << "Stack Overflow !" << endl;
            return;
        }

        // ----------------------------- //

        int i = freeSpot;
        // as now it is occupied then update the freespot
        freeSpot = next[i];
        // now current i changes to previous value
        next[i] = top[sn]; // kyuki current top joh hain woh previous waale ka next ho jaayega
        top[sn] = i;       // now the top is changes to that element

        arr[i] = x; // insert the element at ith position which is vacant

        // ----------------------------- //
    }

    int pop(int sn)
    {
        if (top[sn] == -1)
        {
            cout << " Stack UnderFlow !" << endl;
            return INT_MIN;
        }
        int i = top[sn];
        int x = arr[i];
        top[sn] = next[i];  // because next[i] store the next elemnt of index address
        next[i] = freeSpot; // agla wale freespot daale diye hai
        freeSpot = i;       // now freespot update to delete possition
        return x;
    }

    bool isEmpty(int sn)
    {
        if (top[sn] == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        return freeSpot == -1;
    }
};

int main()
{
    

    return 0;
}
