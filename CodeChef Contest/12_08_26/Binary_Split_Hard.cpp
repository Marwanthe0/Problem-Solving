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
    int z = count(all(s), '0'), o = count(all(s), '1');
    if (z == 0 || o == 0) {
        cout << s << endl;
        return;
    }
    map<string, int> m;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            int j = i, k = i - 1;
            string tmp;
            while (k >= 0 && s[k] == s[i - 1]) {
                tmp = s[i - 1] + tmp;
                k--;
            }
            while (j < n && s[j] == s[i]) {
                tmp.push_back(s[i]);
                j++;
            }
            m[tmp] = i;
        }
    }
    int x = (m.begin())->second - 1;
    cout << x << endl;
    string t = s, tt = s;
    bool flag = false;
    // age 1 then 0 then 1 or age 0 then 1-> meands 1 thakar age 0 thakte hobe.
    int idx = -1, tdx = -1;
    for (int i = x; i >= 0; i--) {
        if (s[i] == '0')
            flag = true;
        if ((s[i] == '1' && flag)) {
            idx = i + 1;
            break;
        }
        if (i == 0)
            idx = i;
    }
    flag = false;
    // age 1 then 0 then 1, or age 0 then 1-> 1 thakte hobe
    for (int i = x + 1; i < n; i++) {
        if (s[i] == '0')
            flag = true;
        if ((s[i] == '1' && flag)) {
            tdx = i - 1;
            break;
        }
        if (i == n - 1)
            tdx = i;
    }
    // cout << idx << " " << tdx << endl;
    // return;
    while (idx < n && t[idx] == '0') {
        t[idx] = '1';
        idx++;
    }
    while (tdx >= 0 && tt[tdx] == '0') {
        tt[tdx] = '1';
        tdx--;
    }
    cout << t << " " << tt << endl;
    return;
    // duitar jonnoi ager problem.

    map<string, int> tm;
    for (int i = 1; i < n; i++) {
        if (t[i] != t[i - 1]) {
            int j = i, k = i - 1;
            string tmp;
            while (k >= 0 && t[k] == t[i - 1]) {
                tmp = t[i - 1] + tmp;
                k--;
            }
            while (j < n && t[j] == t[i]) {
                tmp.push_back(t[i]);
                j++;
            }
            tm[tmp] = i;
        }
    }
    map<string, int> ttm;
    tm[t]++;
    ttm[tt]++;
    for (int i = 1; i < n; i++) {
        if (tt[i] != tt[i - 1]) {
            int j = i, k = i - 1;
            string tmp;
            while (k >= 0 && tt[k] == tt[i - 1]) {
                tmp = tt[i - 1] + tmp;
                k--;
            }
            while (j < n && tt[j] == tt[i]) {
                tmp.push_back(tt[i]);
                j++;
            }
            ttm[tmp] = i;
        }
    }
    cout << (tm.begin())->first << " " << (ttm.begin())->first << endl;
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