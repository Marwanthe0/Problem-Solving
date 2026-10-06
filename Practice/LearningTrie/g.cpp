#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define M 1000000007
#define N 1000005
#define int long long
#define INF (1LL << 62)
#define endl '\n'
#define all(v) v.begin(), v.end()
template<class T, class Cmp = less<T>>
using pbds = tree<T,null_type,Cmp,rb_tree_tag, tree_order_statistics_node_update>;


void marwan(){
	int n,k;cin>>n>>k;
	vector<pair<int,int>> v(n);
	for(int i = 0;i < n;i++){
		cin>>v[i].first;
		v[i].second = i;
	}
	sort(all(v));
	vector<int> ans(n,0);
	pbds<int> pb;
	int count = 0,sum = 0;
	for(auto [x,idx]:v){
		ans[idx] = count*x - sum;
		ans[idx] += pb.order_of_key(idx);
		sum += x;
		count++;
		pb.insert(idx);
	}
	for(auto vl:ans){
		if(vl <= k - 2) cout<<vl<<endl;
		else cout<<-1<<endl;
	}

}

int32_t main(){
	ios:: sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;cin>>t;
	// for(int cs = 1;cs <= t;cs++)
	// {
	// 	// cout<<"Case "<<cs<<": ";
	// 	marwan();
	// }
	marwan();
	return 0;
}