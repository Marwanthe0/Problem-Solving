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
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = [", _print(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif
void marwan(int cs)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    map<int,int> m,tm;
    vector<int> val(n,0);
    for(int i = 0;i + 4 < n;i++){
    	int tans = v[i] + v[i + 2] - v[i + 4];
        val[i] = tans;
        m[tans]++;
        if(i - 2 >= 0 && val[i - 2] == val[i]) tm[tans]++;
        if(i - 4 >= 0 && val[i - 4] == val[i]) tm[tans]++;
    }
    // for(auto vl:val)cout<<vl<<" ";
    // cout << endl;
	int ans = 0;
	for(auto [x,y]:m){
		ans += (y*(y - 1))/2 - tm[tans];
	}
	cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int cs = 1;cs <= t;cs++)
    {
        //cout<<"Case "<<cs<<": ";
        marwan(cs);
    }
    return 0;
}