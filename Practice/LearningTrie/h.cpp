#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) sort(all((x))); (x).erase(unique(all((x))), (x).end())
 int n,m;
 vector<int> v;
 vector<vector<int>> dp;
 int f(int i,int j){
 	if(i == n) {
 		return j == 0;}
 	if(dp[i][j] != -1) return dp[i][j];
 	int tans = 0;
 	// cerr<<i<<" "<<j<<endl;
 	for(int k = 0;k <= min(v[i],m - 1);k++){
 		int tk = v[i]/m;
 		if(k <= v[i]%m) tk++;
 		// cerr<<i<<" "<<j<<" "<<k<<" "<<tk<<endl;
 		tans = (tans + (f(i + 1,(j - k + m)%m)*1ll*tk)%M)%M;
 	}
 	return dp[i][j] = tans;
 }
 void marwan() {
   cin >> n >> m;
   v.assign(n, 0);
   for (auto& vl : v) cin >> vl;
   dp.assign(n + 1, vector<int>(m + 1, -1));
   int ans = f(0,0);
   cout<<ans<<endl;
 }
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--) marwan();
    return 0;
}