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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &vl : a)
    cin >> vl;
  int count = 0;
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        count++;
      }
    }
  }
  cout << "Array is sorted in " << count << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a.back() << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}