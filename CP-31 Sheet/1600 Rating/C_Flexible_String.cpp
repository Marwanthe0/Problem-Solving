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
int f(int i, unordered_set<char> &ts, unordered_set<char> &temp, string &s, string &t) {
    if (i == 0) {
        int cnt = 0, sum = 0ll;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i] || temp.count(s[i])) {
                cnt++;
            } else
                sum += (cnt * (cnt + 1)) / 2ll, cnt = 0;
        }
        sum += (cnt * (cnt + 1)) / 2ll;
        return sum;
    }
    int csum = 0;
    for (auto c : ts) {
        if (!temp.count(c)) {
            temp.insert(c);
            csum = max(csum, f(i - 1, ts, temp, s, t));
            temp.erase(c);
        }
    }
    return csum;
}
// int ft(string &s, string &t) {
//     int sum = 0, cnt = 0;
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == t[i])
//             cnt++;
//         else
//             sum += (cnt * (cnt + 1)) / 2ll, cnt = 0;
//     }
//     sum += (cnt * (cnt + 1)) / 2ll;
//     return sum;
// }
void marwan() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    unordered_set<char> st;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            st.insert(s[i]);
        }
    }
    k = min(k, (int)st.size());
    unordered_set<char> ts = st, ss;
    cout << f(k, ts, ss, s, t) << endl;
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