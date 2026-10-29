#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  vector<int> v;
  for (auto c : s)
    v.push_back(c - '0');
  int mnpos = 0;
  int count = k;
  vector<int> ans;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (count >= 0 && v[i] < v[mnpos]) {
      if (v[i] == 0 && ans.empty())
        continue;
      mnpos = i;
    }
    if (count >= 0)
      count--;
    cerr << i << " " << mnpos << " " << count << endl;
    if ((i == n - 1 && ans.size() < (n - k)) || count < 0) {
      count = k - (i);
      ans.push_back(v[mnpos]);
      i = mnpos;
      cnt++;
      mnpos++;
    }
  }
  ans.push_back(v[mnpos]);
  for (auto vl : ans)
    cout << vl;
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    marwan();
  return 0;
}