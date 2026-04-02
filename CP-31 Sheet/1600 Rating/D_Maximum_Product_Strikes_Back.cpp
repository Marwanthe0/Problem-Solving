#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
pair<pair<int, int>, int> f(int l, int r, vector<int> &v) {
    int a = 0, b = 0, c = 0;
    cerr << l << " " << r << endl;
    pair<int, int> ans = {l, r + 1};
    int first = -1, firsta = 0, firstc = 0;
    int mx = 0;
    for (int i = l; i <= r; i++) {
        if (v[i] == -2)
            a++;
        else if (v[i] == -1)
            b++;
        else if (v[i] == 2)
            c++;
        if ((a + b) % 2) {
            if (first == -1) {
                first = i + 1, firsta = a, firstc = c;
            } else if ((a - firsta) + (c - firstc) > mx) {
                ans = {first, i + 1};
                mx = (a - firsta) + (c - firstc);
            }
        } else if ((a + c) > mx) {
            ans = {l, i + 1}, mx = a + c;
        }
    }
    pair<pair<int, int>, int> tans = {ans, mx};
    return tans;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int start = 0, mx = 0;
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            if (start < i) {
                pair<pair<int, int>, int> tmp = f(start, i - 1, v);
                if (tmp.second > mx) {
                    mx = tmp.second, ans = tmp.first;
                }
            }
            start = i + 1;
        }
    }
    pair<pair<int, int>, int> tmp = f(start, n - 1, v);
    if (tmp.second > mx) {
        mx = tmp.second, ans = tmp.first;
    }
    cout << ans.first << " " << (n - ans.second) << endl;
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