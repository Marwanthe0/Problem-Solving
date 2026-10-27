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
  int n, k;
  cin >> n >> k;
  vector<int> v(n), pf(n, 0), age(n, -1), agesum(n, 0);
  for (auto &vl : v)
    cin >> vl;
  for (int i = 0; i < n; i++)
    pf[i] += v[i] + (i ? pf[i - 1] : 0);
  int mxsum = 0, mxp = k - 1;
  for (int i = k - 1; i < n; i++) {
    int j = i - k + 1;
    int sum = pf[i] - (j ? pf[j - 1] : 0);
    if (sum > mxsum)
      mxsum = sum, mxp = j;
    age[i] = mxp;
    agesum[i] = mxsum;
  }
  mxsum = 0;
  int a = 0, b = 0;
  for (int i = 2 * k - 1; i < n; i++) {
    int j = i - k + 1;
    int sum = pf[i] - (j ? pf[j - 1] : 0);
    if (sum + agesum[j - 1] > mxsum) {
      mxsum = sum + agesum[j - 1], a = age[j - 1] + 1, b = j + 1;
    }
  }
  cout << a << " " << b << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}