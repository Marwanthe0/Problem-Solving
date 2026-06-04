// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000000
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define forn for (int i = 0; i < n; i++)
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// void marwan() {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (auto &vl : v)
//         cin >> vl;
//     vector<int> dp(n, 1), last(n, 0);
//     map<int, int> m;
//     for (int i = 0; i < n; i++) {
//         m[v[i]] = i;
//         if (m.count(v[i] - 1)) {
//             dp[i] = dp[m[v[i] - 1]] + 1;
//             // if (dp[i - 1] < dp[m[v[i] - 1]])
//             last[i] = m[v[i] - 1] + 1;
//         }
//     }
//     int mx = *max_element(all(dp));
//     int idx = n - 1;
//     for (int i = n - 1; i >= 0; i--) {
//         if (dp[i] == mx) {
//             idx = i;
//             break;
//         }
//     }
//     vector<int> ans;
//     ans.push_back(idx + 1);
//     int x = last[idx];
//     while (x) {
//         ans.push_back(x);
//         x = last[x - 1];
//     }
//     reverse(all(ans));
//     cout << mx << endl;
//     for (auto vl : ans)
//         cout << vl << " ";
//     cout << endl;
// }
// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     marwan();
//     return 0;
// }
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
    int n;
    cin >> n;
    map<int, int> dp;
    vector<int> v(n);
    int ans = 0, val;
    for (auto &vl : v) {
        cin >> vl;
        dp[vl] = dp[vl - 1] + 1;
        if (dp[vl] > ans) {
            ans = dp[vl];
            val = vl;
        }
    }
    cout << ans << endl;
    vector<int> uttor;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == val) {
            uttor.push_back(i + 1);
            val--;
        }
    }
    reverse(all(uttor));
    for (auto vl : uttor)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}