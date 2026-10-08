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
int n;
string s;
vector<int> dp;
int f(int i){
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];
	int ans = INT_MAX;
	if(s[i] == '.'){
		ans = min(ans,f(i + 2) + 1);
		ans = min(ans,f(i + 3) + 1);
	}
	else {
		ans = min(ans,f(i + 1));
	}
	return dp[i] = ans;
}
void marwan(int cs)
{
    cin>>n;
    cin>>s;
    dp.assign(n + 1,-1);
    cout<<f(0)<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int cs = 1;cs <= t;cs++)
    {
        cout<<"Case "<<cs<<": ";
        marwan(cs);
    }
    return 0;
}