// Fizz buzz is a group word game for children to teach them about division. Players take turns to count incrementally, replacing any number divisible by three with the word "fizz", and any number divisible by five with the word "buzz".

#include <iostream>
using namespace std;


int main()
{
    int i;
    int n;
    cout << "Enter how far to go for FizzBuzz: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        if (i % 5 == 0 && i % 3 == 0)
            printf("FizzBuzz\n");
        else if (i % 3 == 0)
            printf("Fizz\n");
        else if (i % 5 == 0)
            printf("Buzz\n");
        else
            printf("%d\n", i);
    }
    return 0;
}