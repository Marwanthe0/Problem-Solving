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
vector<int> val = {1,0,0,0,1,0,1,0,2,1};
void marwan(int cs)
{
    int n,k;cin>>n>>k;
    int x = n;
    for(int i = 0;i < min(10ll,k);){
    	int sum = 0;
    	if(x == 0) sum = 1;
    	while(x) sum += val[x%10],x/= 10;
    	x = sum;
    	i++;
    	if(x == 0){
    		int rem = k - i;
    		if(rem&1) cout<<1<<endl;
    		else cout<<0<<endl;
    		return;
    	}
    }
    cout<<x<<endl;
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