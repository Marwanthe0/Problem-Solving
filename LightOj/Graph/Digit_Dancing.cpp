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
set<int> primes = {2, 3, 5, 7, 11, 13};
bool sorted(vector<int> v) {
    vector<int> t;
    for (auto &vl : v)
        t.push_back(abs(vl));
    return is_sorted(all(t));
}
int f(int cur, vector<int> t) {
    if (sorted(t))
        return 0;
    if (cur >= 9)
        return 1e9;
    int pos = 0, ans = f(cur + 1, t);
    for (int i = 0; i < 8; i++) {
        if (abs(t[i]) == cur) {
            pos = i;
            break;
        }
    }
    // cerr << cur << endl;
    // for (auto vl : t)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 0; i < 8; i++) {
        if (pos == i)
            continue;
        if (t[pos] * t[i] >= 0)
            continue;
        if (primes.count(abs(t[pos]) + abs(t[i]))) {
            vector<int> tt;
            for (auto vl : t)
                tt.push_back(vl);
            int x = t[pos];
            if (pos > i) {
                t.erase(t.begin() + pos);
                t.insert(t.begin() + i, x);
            } else {
                t.erase(t.begin() + pos);
                t.insert(t.begin() + i - 1, x);
            }
            ans = min(ans, f(cur + 1, t) + 1);
            x = tt[pos];
            if (pos > i) {
                tt.erase(tt.begin() + pos);
                tt.insert(tt.begin() + i + 1, x);
            } else {
                tt.erase(tt.begin() + pos);
                tt.insert(tt.begin() + i, x);
            }
            ans = min(ans, f(cur + 1, tt) + 1);
        }
    }
    return ans;
}
void marwan(int cs) {
    vector<int> v(8);
    for (auto &vl : v)
        cin >> vl;
    cout << f(1, v) << endl;
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