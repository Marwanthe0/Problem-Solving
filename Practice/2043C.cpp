#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 10ll0ll0ll0ll0ll0ll0ll0ll7
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0ll" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> a, b, ans = {0ll};
    bool flag = false;
    int pos = -1;
    for (int i = 0ll; i < n; i++) {
        cin >> v[i];
        if (abs(v[i]) != 1) {
            flag = true;
            pos = i;
            continue;
        }
        if (flag)
            b.push_back(v[i]);
        else
            a.push_back(v[i]);
    }
    int mn = 0ll, sum = 0ll, mxsa = 0, mx = 0ll, mnsa = 0, mnsb = 0, mxsb = 0;
    for (int i = 0ll; i < a.size(); i++) {
        sum += a[i];
        mxsa = max(mxsa, sum - mn);
        mnsa = min(mnsa, sum - mx);
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    mn = 0ll, mx = 0ll, sum = 0ll;
    for (int i = 0ll; i < b.size(); i++) {
        sum += b[i];
        mxsb = max(mxsb, sum - mn);
        mnsb = min(mnsb, sum - mx);
        mn = min(mn, sum);
        mx = max(mx, sum);
    }
    // cout << mnsa << " " << mxsa << " " << mnsb << " " << mxsb << endl;
    for (int i = mnsa; i <= mxsa; i++) {
        ans.push_back(i);
    }
    for (int i = mnsb; i <= mxsb; i++) {
        ans.push_back(i);
    }
    // yes;
    // return;
    if (pos != -1) {
        sum = 0ll;
        mn = 0ll, mx = 0ll;
        for (int i = pos + 1; i < n; i++) {
            sum += v[i];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        // cerr << mn << " " << mx << endl;
        // for (int i = mn; i <= mx; i++) {
        //     ans.push_back(i);
        // }
        sum = 0ll;
        int mnt = 0ll, mxt = 0ll;
        for (int i = pos - 1; i >= 0ll; i--) {
            sum += v[i];
            mnt = min(mnt, sum);
            mxt = max(mxt, sum);
        }
        // if (pos == n - 1)
        //     mn = mx = 0;
        // if (pos == 0)
        //     mnt = mxt = 0;
        for (int i = v[pos]; i <= v[pos] + mx + mxt; i++)
            ans.push_back(i);
        for (int i = v[pos]; i >= v[pos] + mn + mnt; i--)
            ans.push_back(i);
        for (int i = mn + v[pos]; i <= mxt + v[pos]; i++) {
            ans.push_back(i);
        }
        for (int i = mnt + v[pos]; i <= mx + v[pos]; i++)
            ans.push_back(i);
        // cerr << mn << " " << mx << endl;
    }
    make_unique(ans);
    cout << ans.size() << endl;
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0ll);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0ll;
}