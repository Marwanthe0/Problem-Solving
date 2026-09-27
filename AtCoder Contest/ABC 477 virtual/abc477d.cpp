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
void marwan() {
  int n, q;
  cin >> n >> q;
  vector<char> v(n + 1, 'a'), crs(q + 1);
  vector<int> t(n + 1, 0);
  set<int> st;
  char last = 'a';
  for (int i = 0; i < q; i++) {
    int op;
    if (op == 1) {
      int pos;
      cin >> pos;
      
    } else {
      char ch;
      cin >> ch;
      last = ch;
    }
    crs[i] = last;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}