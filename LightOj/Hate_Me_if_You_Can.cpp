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
  cout << "Case " << cs << ": ";
  int x, y, z;
  cin >> x >> y >> z;
  int teamrun = 0, caprun = 0, teamrun2 = 0;
  int ulta = (x - 1 / 6), caps = x - ulta, uran = 0;
  caprun = caps * 6, uran = ulta * 3;
  while (1) {
    int trun = caprun + uran;
    if (trun < y)
      break;
    int ncaprun = caprun, nuran = uran;
    
  }
  for (int i = 1; i <= x; i++) {
    if (i % 6 != 0)
      caprun += 6, teamrun2 += 6;
    else
      teamrun2 += 3;
    teamrun += 6;
  }
  if (caprun >= z && teamrun2 >= y)
    cout << "Like a Boss!" << endl;
  else if (teamrun >= y)
    cout << "Bravo Captain!" << endl;
  else
    cout << "Love You Captain!" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}