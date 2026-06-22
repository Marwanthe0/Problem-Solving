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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m, 0)), t(n, vector<int>(m, 0ll)), pt(n, vector<int>(m, 0ll));
    int a = 0ll, b = 0ll;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            t[i][j] = s[j] - '0';
            pt[i][j] = t[i][j];
            if (t[i][j])
                a += v[i][j];
            else
                b += v[i][j];
            if (j)
                pt[i][j] += pt[i][j - 1];
            if (i)
                pt[i][j] += pt[i - 1][j];
            if (i && j)
                pt[i][j] -= pt[i - 1][j - 1];
            cerr << pt[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << endl;
    int dif = abs(a - b), kk = k * k;
    if (!dif) {
        yes;
        return;
    }
    auto f = [&](int i, int j) {
        int sum = pt[i][j];
        // cerr << sum << ":";
        if (i - k >= 0)
            sum -= pt[i - k][j];
        // cerr << sum << ":";
        if (j - k >= 0)
            sum -= pt[i][j - k];
        // cerr << sum << ":";
        if (i - k >= 0 && j - k >= 0) {
            sum += pt[i - k][j - k];
        }
        // cerr << sum << endl;
        return sum;
    };
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= k - 1 && j >= k - 1) {
                cerr << i << " " << j << endl;
                int x = f(i, j);
                int y = kk - x;
                cerr << x << endl;
                s.insert(abs(x - y));
            }
        }
    }
    cerr << dif << "::";
    int g = 0;
    for (auto vl : s) {
        // cerr << vl << " ";
        g = __gcd(g, vl);
    }
    if (g && dif % g == 0) {
        yes;
    } else
        no;
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