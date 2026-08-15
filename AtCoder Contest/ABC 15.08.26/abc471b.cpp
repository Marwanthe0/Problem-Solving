#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto &c : s) {
            if (c >= 'A' && c <= 'Z')
                c = (c - 'A') + 'a';
        }
        // cout << s << endl;
        m[s]++;
    }
    int mx = 0;
    string ans;
    for (auto [x, y] : m) {
        // cout << x << " " << y << endl;
        if (y > mx) {
            mx = y;
            ans = x;
        }
    }
    cout << mx << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}