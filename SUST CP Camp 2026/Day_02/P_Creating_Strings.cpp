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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
map<char, int> m;
set<string> ans;

void marwan() {
  string s;
  cin >> s;
  sort(all(s));
  do {
    ans.insert(s);
  } while (next_permutation(all(s)));
  cout << ans.size() << endl;
  for (auto vl : ans)
    cout << vl << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}