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
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (auto &vl : v) {
        cin >> vl;
        sum += vl;
    }
    if (sum) {
        minus;
        return;
    }
    vector<int> cur, pos(n + 1, 0);
    int x = -1 * (n - 1);
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        cur.push_back(x);
        x += 2;
    }
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        // cout << v[i] - cur[i] << " ";
        int val = v[i] - cur[i];
        pos[i + 1] += val;
        if (pos[i + 1] <= 0 || pos[i + 1] > n || ans[pos[i + 1]] != 0) {
            minus;
            return;
        }
        ans[pos[i + 1]] = i + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}