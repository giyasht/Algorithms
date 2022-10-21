#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <cstring>
#include <time.h>
#include <chrono>
#include <random>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, arr) for (auto it = arr.begin(); it != arr.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1e9+7;
 
template<typename T> bool sortbysec(pair<T, T> &arr, pair<T, T> &b)
{
    return (arr.second < b.second);
}
template<typename T> auto comp = [](pair<T, T> &arr, pair<T, T> &b)
{
    return abs(arr.first) + abs(arr.second) < abs(b.first) + abs(b.second);
};
 
template<typename T> void read(T i, T n, vector<T> &arr)
{
    for (T j = i; j < n; j++)
        cin >> arr[j];
}


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    for(int i = 0; i<2*n; i++) {
        if(s[i]=='1') cnt++;
    }
    if(cnt%2) {
        cout<<"-1\n";
        return;
    }
    vi ans;
    int m = 0;
    for(int i = 0; i<2*n; i+=2) {
        if(s[i]!=s[i+1]) {
            if(s[i]-'0'==m) ans.pb(i+1);
            else ans.pb(i+2);
            m^=1;
        }
    }
    cout<<ans.size()<<" ";
    for(auto i : ans) cout<<i<<" ";
    cout<<endl;
    for(int i = 1; i<=2*n; i+=2) cout<<i<<" ";
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
