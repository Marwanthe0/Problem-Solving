#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define M 1000000007
#define N 5000008
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
vector<int> ans(N + 1, 0);
void pre() {
  for(int i = 2;i <= N;i++) ans[i] =i;
  for (int i = 2; i <= N; i++) {
    if(ans[i] == i){
      ans[i] = i - 1;
      for (int j = 2*i; j <= N; j += i) {
        ans[j] -= ans[j]/i;
      }
    }
  }
  for (int i = 2; i <= N; i++) {
    // if(i <= 20) cerr<<i<<" "<< ans[i]<<endl;
    ans[i] = (ans[i]*1ll*ans[i]);
  }
  // for(int i = 0;i <= 100;i++)cout<<i<<" "<<ans[i]<<endl;
  // return;
  for(int i = 1;i <= N;i++) ans[i] += ans[i - 1];
}
void marwan(int cs) {
  int a,b;
  cin>>a>>b;
  cout<<ans[b] - ans[a - 1]<<endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout<<"Case "<<i<<": ";
    marwan(i);
  }
  return 0;
}