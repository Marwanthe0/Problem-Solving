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

// 3 1 2 4
// 1 3 2 4
//5 4 3 2 1
//1 4 3 2 5
//1 2 3 4 5

int n;
vector<vector<int>> g;
vector<int> vis;
int cnt;
void dfs(int u){
	vis[u] = 1;
	cnt++;
	for(auto v:g[u]){
		if(!vis[v]) dfs(v);
	}
}
void marwan(int cs)
{
    cin >> n;
    g.assign(n + 1,vector<int>());
    for(int i = 1;i <= n;i++){
    	int x;cin>>x;
    	if(i != x)
    	g[i].push_back(x);
    	g[x].push_back(i);
    }
    int ans = 0;
    vis.assign(n + 1,0);
    for(int i = 1;i <= n;i++){
    	if(!vis[i]){
    		cnt = 0;
    		dfs(i);
    		ans += cnt - 1;
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
    for(int cs = 1;cs <= t;cs++)
    {
        cout<<"Case "<<cs<<": ";
        marwan(cs);
    }
    return 0;
}