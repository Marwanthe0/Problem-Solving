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
    int n;
    cin>>n;
    string s;cin>>s;
    vector<int> ans;
    stack<int> st;
    for(int i = 0;i < n;i++){
    	if(s[i] == '3') continue;
    	else if(s[i] == '1') st.push(i + 1);
    	else {
    		if(st.size()){
    		st.pop();
    		ans.push_back(i + 1);
    		}
    	}
    }
   	while(st.size()){
   		ans.push_back(st.top());
   		st.pop();
   	}
   	sort(all(ans));
    cout<<ans.size()<<endl;
    for (auto vl : ans) cout << vl << " ";
    cout << endl;
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