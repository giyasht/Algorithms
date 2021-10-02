#include <stdio.h>
#define bool int

/* Function to check if x is power of 4*/
bool isPowerOfFour(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n % 4 != 0)
      return 0;
    n = n / 4;
  }
  return 1;
}

/*Driver program to test above function*/
int main()
{
  int test_no = 64;
  if (isPowerOfFour(test_no))
    printf("%d is a power of 4", test_no);
  else
    printf("%d is not a power of 4", test_no);
  getchar();
}