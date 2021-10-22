// this is the optimized code for finding binary power of large numbers modulo 10^9+7.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (ll)(1e7+7)
ll bp(ll x,ll y){
 x%=mod;
   ll r=1;
  while (y>0)
  {
    if(y&1){r=(r%mod)*(x%mod);r=r%mod;}
    x=(x%mod)*(x%mod); x= (x%mod);
y>>=1;
  }
  return r%mod;
}


int main()
{ios_base::sync_with_stdio(false);
    ll t=1;cin>>t;
while(t--){
  ll a,b;
 cout<<"Enter two numbers a and b"<<endl;
 cin>>a>>b;
 cout<<"Value of a^b mod 1e9+7 is:"<<endl;
 cout<<bp(a,b)<<endl;
}
}
