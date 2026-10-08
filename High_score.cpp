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
int n,m;
vector<vector<pair<int,int>>> g;
vector<tuple<int,int,int>> edges;
vector<int> dist;
void marwan(int cs)
{
	cin>>n>>m;
	g.assign(n + 1,vector<pair<int,int>>());
	dist.assign(n + 1,INT_MIN);
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		edges.push_back({a,b,c});
	}

	for(int i = 1;i < n;i++){
			for(auto [u,v,w]:edges){
				if(dist[u] + w > dist[v]){
					dist[v] = dist[u] + w;
				}
			}
	}
	cout<<dist[n]<<endl;
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