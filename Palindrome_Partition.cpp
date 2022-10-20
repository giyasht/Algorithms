#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(s[0]=='0'){
            for(int i=0;i<2*n;i++){
                if(s[i]=='1'){
                    s[i]='0';
                }else{
                    s[i]='1';
                }
            }
        }
        vector <ll> v;
        ll cnt;
        ll flag=0;
        ll p;
        for(int i=0;i<2*n;i++){
            if(s[i]=='0'){
                v.push_back(i);
            }
            if(s[i]!=s[2*n-i-1]){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"1\n";
            cout<<2*n<<"\n";
            continue;
        }
        if(v.size()==0){
            cout<<"-1\n";
        }else{
            cnt=2*n-1-v.back();
            for(int i=v.size()-1;i>=1;i--){
                if(v[i]-v[i-1]-1!=cnt){
                    flag=1;
                    cout<<"2\n";
                    cout<<v[i-1]+1<<" "<<2*n-1-v[i-1]<<"\n";
                    break;
                }
            }
            if(flag==0){
                cout<<"2\n";
                cout<<v[v.size()-2]+2<<" "<<2*n-2-v[v.size()-2]<<"\n";
            }
        }
    }
  return 0;
}
