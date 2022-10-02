// CPP code to implement Freivald’s Algorithm
#include <bits/stdc++.h>
using namespace std;

#define N 2

// Function to check if ABx = Cx
int freivald(int a[][N], int b[][N], int c[][N])
{
	// Generate a random vector
	bool r[N];
	for (int i = 0; i < N; i++)
		r[i] = random() % 2;

	// Now comput B*r for evaluating
	// expression A * (B*r) - (C*r)
	int br[N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			br[i] = br[i] + b[i][j] * r[j];

	// Now comput C*r for evaluating
	// expression A * (B*r) - (C*r)
	int cr[N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cr[i] = cr[i] + c[i][j] * r[j];

	// Now comput A* (B*r) for evaluating
	// expression A * (B*r) - (C*r)
	int axbr[N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			axbr[i] = axbr[i] + a[i][j] * br[j];

	// Finally check if value of expression
	// A * (B*r) - (C*r) is 0 or not
	for (int i = 0; i < N; i++)
		if (axbr[i] - cr[i] != 0)
			false;

	return true;
}

// Runs k iterations Freivald. The value
// of k determines accuracy. Higher value
// means higher accuracy.
bool isProduct(int a[][N], int b[][N],
			int c[][N], int k)
{
	for (int i=0; i<k; i++)
		if (freivald(a, b, c) == false)
			return false;
	return true;
}

// Driver code
int main()
{
	int a[N][N] = { { 1, 1 }, { 1, 1 } };
	int b[N][N] = { { 1, 1 }, { 1, 1 } };
	int c[N][N] = { { 2, 2 }, { 2, 2 } };
	int k = 2;
	if (isProduct(a, b, c, k))
		printf("Yes");
	else
		printf("No");
	return 0;
}

//Code written by Yash Gupta