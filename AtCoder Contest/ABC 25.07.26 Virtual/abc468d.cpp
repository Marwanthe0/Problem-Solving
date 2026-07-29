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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0ll;
    string t;
    for (int i = 0; i < n; i++) {
        t.push_back(s[i]);
        if (i != n - 1)
            t.push_back('#');
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        int l = i, r = i;
        while (l >= 0 && r < n) {
            if (s[l] == s[r]) {
                ans++, l--, r++;
            } else if (!flag) {
                ans++, flag = 1, l--, r++;
            } else
                break;
        }
    }
    cerr << t << endl;
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == '#') {
            int flag = 0;
            int l = i, r = i;
            while (l >= 0 && r < (int)t.size()) {
                if (t[l] == t[r]) {
                    if (t[l] != '#') {
                        // cerr << l << " " << r << endl;
                        ans++;
                    }
                    l--, r++;
                } else if (!flag) {
                    // cerr << l << " " << r << endl;
                    ans++, flag = 1, l--, r++;
                } else
                    break;
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}