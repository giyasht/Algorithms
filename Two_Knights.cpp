#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;


int main() 
{
    ull n;
    cin >> n;
    
    for(ull i = 1 ; i <= n ; i++)
    {
        if(i == 1)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << ((i*i)*(i*i-1)/2) - (4*(i-1)*(i-2)) << '\n';
        }
    }
    
	return 0;
}
