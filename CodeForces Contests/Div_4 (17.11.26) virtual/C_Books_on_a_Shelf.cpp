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
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    vector<int> a = v, t;
    make_unique(a);
    for (auto &[x, y] : m) {
        if (y > 1)
            t.push_back(x);
        y -= 2;
    }
    sort(all(t));
    reverse(all(t));
    int ans = (int)a.size() + (int)t.size();
    cout << ans << endl;
    for (auto vl : a)
        cout << vl << " ";
    for (auto [x, y] : m) {
        if (y <= 0)
            continue;
        while (y--)
            cout << x << " ";
    }
    for (auto vl : t)
        cout << vl << " ";
    cout << endl;
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