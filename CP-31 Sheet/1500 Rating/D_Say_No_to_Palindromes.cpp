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
void marwan() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> ans = {"abc", "acb", "bac", "bca", "cab", "cba"};
    string dance;
    int mx = INT_MAX;
    for (auto cand : ans) {
        int count = 0, idx = 0;
        for (auto c : s) {
            count += cand[idx % 3] != c;
            idx++;
        }
        if (count < mx) {
            mx = count, dance = cand;
        }
    }
    vector<vector<int>> tans(6, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            tans[j][i] = (s[i] != ans[j][i % 3]);
            if (i)
                tans[j][i] += tans[j][i - 1];
        }
    }
    // for (int i = 0; i < 6; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << tans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int temp = INT_MAX;
        for (int i = 0; i < 6; i++) {
            temp = min(temp, tans[i][r] - (l ? tans[i][l - 1] : 0));
        }
        cout << temp << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}