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
    int n,k;
    cin>>n>>k;
    n++,k++;
    vector<int> v(n);
    for(auto &vl:v)cin>>vl;
    int l = *max_element(all(v)),r = accumulate(all(v),0ll),ans = -1;
	auto ok = [&](int mid){
		int tsum = 0,count = 0;
		for(int i = 0;i < n;i++){
			if(tsum + v[i] <= mid){
				tsum += v[i];
			}
			else count++,tsum = v[i];
		}
		return count < k;
	};
	auto path = [&](int mid)->vector<int>{
		int tsum = 0,count = 1;
		vector<int> pth;
		for(int i = 0,rem = n;i < n;i++,rem--){
			if(k - count == rem){
				pth.push_back(tsum);
				for(int j = i;j < n;j++) pth.push_back(v[j]);
				return pth;
			}
			if(tsum + v[i] <= mid){
				tsum += v[i];
			}
			else {
				count++;
				pth.push_back(tsum);
				tsum = v[i];
			}
		}
		pth.push_back(tsum);
		return pth;
	};
	while(l <= r){
		int mid = l + (r - l)/2;
		bool kk = ok(mid);
		if(kk){
			r = mid - 1,ans = mid;
		}
		else l = mid + 1;
	}
	cout<<ans<<endl;
	vector<int> anspath = path(ans);
	for(auto vl:anspath) cout<<vl<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cout<<"Case "<<i<<": ";
        marwan(t - i);
    }
    return 0;
}