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
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    int a, b;
    cin >> a >> b;
    int dif = a - b;
    vector<int> ans;
    for (int i = 1; i * i <= dif; i++) {
        if ((dif % i) == 0) {
            ans.push_back(i);
            ans.push_back(dif / i);
        }
    }
    make_unique(ans);
    int count = 0;
    for (auto vl : ans)
        if (vl > b) {
            cout << vl << " ";
            count++;
        }
    if (!count)
        cout << "impossible" << endl;
    else
        cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}