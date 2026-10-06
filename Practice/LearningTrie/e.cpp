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
    for(auto &vl:v)cin>>vl;
    if(n == k){
    	cout<<"Richman"<<endl;
    	return;
    }
    int cntz = count(all(v),0);
    if(cntz > k) {
    	cout<<"Impossible"<<endl;
    	return;
    }
    k -= cntz;
    vector<int> t;
    for(auto vl:v)if(vl) t.push_back(vl);
    v = t;

    int sum = 0;
    for(int i = 0;i < k;i++){
    	sum += v[i];
    }
    int mn = *min_element(v.begin() + k,v.end());
    if(mn == 0) {
    	cout<<"Impossible"<<endl;
    } else
      cout << sum + mn - 1 << endl;
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