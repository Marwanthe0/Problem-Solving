#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) sort(all((x))); (x).erase(unique(all((x))), (x).end())
void marwan(int cs)
{
    int n,k;cin>>n>>k;
    vector<int> v(n);
    int ans = 0;
    for(auto &vl:v){cin>>vl;ans += __builtin_popcount(vl);}
    for(int i = 0;i < 60;i++){
        
        int val = (1<<i);
        for(auto vl:v){
            if((val&vl) == 0 && k >= val){
                ans++;
                k -= val;
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        marwan(i);
    }
    return 0;
}