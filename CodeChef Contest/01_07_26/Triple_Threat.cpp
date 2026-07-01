#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    k = min(k, 3 * n);
    string s;
    s.assign(3 * n, '0');
    int idx = s.size() - 1;
    while (idx >= 2 * n && k) {
        s[idx] = '1';
        k--;
        idx--;
    }
    idx = 2 * n - 1;
    while (k > 0) {
        s[idx] = '1';
        k--;
        if (k > 0) {
            s[idx - n] = '1';
            k--;
        }
        idx--;
    }
    cout << s << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}