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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n, 0), os(n, 0), xs(n, 0), pf(n, 0), mx(n, -1);
    int o = 0, x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o')
            o++;
        else
            x++;
        os[i] = o;
        xs[i] = x;
        pf[i] = o - x;
    }
    int l = 0, r = 0;
    o = 0, x = 0;
    long double ans = 0;
    vector<int> lagbe(n, -1);
    while (r < n) {
        if (s[r] == 'o')
            o++;
        else
            x++;
        while (l < r && s[l] == 'x')
            l++;
        if (o == k) {
            lagbe[r] = l;
            ans = max(ans, ((long double)(o)) / ((long double)(o + x)));
        }
        while (o >= k) {
            if (s[l] == 'o')
                o--;
            else
                x--;
            ans = max(ans, ((long double)(o)) / ((long double)(o + x)));
            l++;
        }
        r++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o')
            cnt++;
        else
            cnt = 0;
        mx[i] = cnt;
    }
    int mn = INT_MAX, mnidx = 0;
    for (int i = 0; i < n; i++) {
        if (lagbe[i] != -1) {
            // cout << i << " " << lagbe[i] << " " << os[i] - (lagbe[i] ? os[lagbe[i] - 1] : 0) << " " << xs[i] - (lagbe[i] ? xs[lagbe[i] - 1] : 0) << " " << mx[lagbe[i]] << endl;
            int r = i, l = lagbe[i];
            int xss = xs[r] - (l ? xs[l - 1] : 0), oss = os[r] - (l ? os[l - 1] : 0);
            if (mx[l] > 1)
                oss += (mx[l] - 1);
            long double tans = (long double)(oss) / ((long double)(oss + xss));
            ans = max(ans, tans);
        }
    }
    cout << setprecision(20) << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}