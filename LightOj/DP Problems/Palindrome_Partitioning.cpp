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
string s;
int n;
struct Manacher {
    string t;
    vector<int> p;
    int n;
    int m;

    Manacher(const string &s) {
        n = s.size();
        if (n == 0) {
            m = 0;
            return;
        }

        t.reserve(2 * n + 1);
        for (char c : s) {
            t.push_back('#');
            t.push_back(c);
        }
        t.push_back('#');
        m = (int)t.size();
        p.assign(m, 0);

        for (int i = 0, l = 0, r = -1; i < m; ++i) {
            int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < m && t[i - k] == t[i + k])
                ++k;
            p[i] = --k;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
    }

    bool isPalindrome(int l, int r) const {
        if (l > r)
            return true;
        if (n == 0)
            return true;
        int center = l + r + 1;
        int needed = r - l + 1;
        if (center < 0 || center >= m)
            return false;
        return p[center] >= needed;
    }
};

void marwan(int cs) {
    cin >> s;
    Manacher man(s);
    string t = man.t;
    n = t.size();
    vector<int> P = man.p;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int x = P[i];
        while (x >= 1) {
            if (i + x < n && i - x >= 0)
                dp[i + x] = min(dp[i + x], 1 + dp[i - x]);
            x -= 2;
        }
    }
    cout << dp[n - 1];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
        if (i != t)
            cout << endl;
    }
    return 0;
}