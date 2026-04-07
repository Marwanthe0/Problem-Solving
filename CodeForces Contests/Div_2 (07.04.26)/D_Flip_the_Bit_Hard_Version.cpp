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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> sp(n + 1, 0);
    bool one = false, zero = false;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        sp[x - 1] = 1;
        if (v[x - 1])
            one = true;
        else
            zero = true;
    }
    bool flag = true, flag2 = true;
    int count = 0, ans = n, count2 = 0;
    vector<int> pr(n, 0), dr(n, 0), pr2(n, 0), dr2(n, 0);
    for (int i = 0; i < n; i++) {
        if (sp[i])
            pr[i] += (count);
        if (flag && v[i]) {
            count++, flag = 0;
        } else if (flag == false && v[i] == 0) {
            count++, flag = 1;
        }

        if (sp[i])
            dr[i] += (count2);
        if (flag2 && v[i] == 0) {
            count2++, flag2 = 0;
        } else if (flag2 == false && v[i]) {
            count2++, flag2 = 0;
        }
    }
    flag = flag2 = true;
    count = count2 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (sp[i])
            pr2[i] += (count);

        if (flag && v[i]) {
            count++, flag = 0;
        } else if (flag == false && v[i] == 0) {
            count++, flag = 1;
        }

        if (sp[i])
            dr2[i] += (count2);
        if (flag2 && v[i] == 0) {
            count2++, flag2 = 0;
        } else if (flag2 == false && v[i]) {
            count2++, flag2 = 0;
        }
    }
    int ans2 = n;
    for (int i = 0; i < n; i++) {
        if (sp[i]) {
            {
                cerr << i + 1 << " " << pr[i] << " " << pr2[i] << "::" << dr[i] << " " << dr2[i] << endl;
                int mx1 = max(pr[i], pr2[i]), mx2 = max(dr[i], dr2[i]);
                if (v[i] && (mx1 % 2 == 0))
                    mx1++;
                if (v[i] == 0 && (mx1 & 1))
                    mx1++;
                if (v[i] == 1 && (mx2 & 1))
                    mx2++;
                if (v[i] == 0 && (mx2 % 2 == 0))
                    mx2++;
                ans = min(ans, mx1);
                ans2 = min(ans2, mx2);
            }
        }
    }
    cerr << endl;
    if (one && zero)
        cout << min(ans, ans2) << endl;
    else if (one)
        cout << ans2 << endl;
    else
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