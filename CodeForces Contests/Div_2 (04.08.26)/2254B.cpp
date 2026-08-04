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
    string s, t;
    cin >> s;
    map<char, int> m;
    for (auto c : s) {
        m[c]++;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] != t.back()) {
            t.push_back(s[i]);
        }
    }
    int ans = (int)(t.size());
    bool flag = false, flag2 = false;
    for (int i = 1; i + 1 < n; i++) {
        if (s[i] != s[i - 1]) {
            if (s[i] != s[i + 1]) {
                flag = true;
                if (s[i - 1] == s[i + 1])
                    flag2 = true;
            }
        }
    }
    cout << ans - flag - flag2 << endl;
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