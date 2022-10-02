// BogoSort also known as permutation sort, stupid sort, slow sort, shotgun sort or monkey sort
// is a particularly ineffective algorithm based on generate and test paradigm.
// The algorithm successively generates permutations of its input
// until it finds one that is sorted.
// For example, if bogosort is used to sort a deck of cards,
// it would consist of checking if the deck were in order, and if it were not,
// one would throw the deck into the air, pick the cards up at random,
// and repeat the process until the deck is sorted.

// PSUEDO CODE
//  while not Sorted(list) do
//      shuffle(list)
//  done

// C++ implementation of Bogo Sort
#include <bits/stdc++.h>
using namespace std;

// To check if array is sorted or not
bool isSorted(int a[], int n)
{
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

// To generate permutation of the array
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}

// Sorts array a[0..n-1] using Bogo sort
void bogosort(int a[], int n)
{
    // if array is not sorted then shuffle
    // the array again
    while (!isSorted(a, n))
        shuffle(a, n);
}

// prints the array
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Driver code
int main()
{
    int a[] = {23, 43, 21, 45, 34, 35, 3, 41};
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    printf("Sorted array :\n");
    printArray(a, n);
    return 0;
}