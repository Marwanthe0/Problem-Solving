#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  char c = 'A';
  string s;
  for (int i = 0; i < n; i++)
    s.push_back(c + i);
  cout << "Case " << cs << ":" << endl;
  int count = 0;
  do {
    cout << s << endl;
    count++;
  } while (next_permutation(all(s)) && count < k);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    marwan(i);
  return 0;
}