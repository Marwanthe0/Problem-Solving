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
vector<int> ans(N,0);
void pre(){
	for(int i = 2;i <= N;i++){
		if(!ans[i]){
			for(int j = i*i;j <= N;j += i){
				ans[j] += (j/i) - 1;
			}
		}
	}
	for(int i = 2;i <= 10;i--){
		cout<<i<<" "<<ans[i]<<endl;
	}
}
void marwan(int cs)
{
    int a,b;cin>>a>>b;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for(int cs = 1;cs <= t;cs++)
    {
        //cout<<"Case "<<cs<<": ";
        marwan(cs);
    }
    return 0;
}