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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    bool zr = false;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0')
            zr = true;
        if (zr)
            t.push_back(s[i]);
    }
    s = t, n = t.size();
    int dig = 0ll;
    string ans;
    for (auto c : s)
        dig += c - '0';
    int tsum = dig;
    for (int i = n - 1; i >= 0; i--) {
        int d = dig % 10;
        ans.push_back(d + '0');
        dig /= 10;
        tsum -= (s[i] - '0');
        dig += tsum;
    }
    if (dig)
        ans.push_back(dig + '0');
    reverse(all(ans));
    cout << ans << endl;
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