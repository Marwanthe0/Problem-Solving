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
bool match(char a, char c) {
    return (a == c) || (a == '?') || (c == '?');
}
void marwan() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> ds(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = j - i;
            if (match(s[i], s[j])) {
                ds[dist][i] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (ds[i][j])
                count++;
            else {
                if (count >= i)
                    ans = max(ans, 2 * i);
                count = 0;
            }
        }
    }
    cout << ans << endl;
    // int ans = 0, last = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         if (match(s[i], s[j])) {
    //             int dist = j - i;
    //             if (j + dist - 1 >= n)
    //                 continue;
    //             bool flag = true;
    //             for (int k = i + 1; k < j; k++) {
    //                 if (!match(s[k], s[k + dist])) {
    //                     flag = false;
    //                     break;
    //                 }
    //             }
    //             if (flag)
    //                 ans = max(ans, 2 * dist);
    //         }
    //     }
    // }
    // cout << ans << endl;
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