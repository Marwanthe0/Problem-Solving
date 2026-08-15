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
vector<int> a;
vector<int> mul(vector<int> a, vector<int> b) {
    int sz = a.size();
    vector<int> c(sz, 0);
    for (int i = 1; i < sz; i++) {
        c[i] = a[b[i]];
    }
    return c;
}
vector<int> binexp(vector<int> a, int b) {
    int sz = a.size();
    vector<int> ans = {0};
    for (int i = 1; i < sz; i++)
        ans.push_back(i);
    // cout << "Before" << endl;
    // for (int i = 1; i < sz; i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    // cout << endl;
    while (b) {
        if (b & 1)
            ans = mul(a, ans);
        a = mul(a, a);
        b >>= 1;
    }
    // ans = mul(ans, a);
    // ans = mul(ans, a);
    // cout << "After" << endl;
    // for (int i = 1; i < sz; i++)
    //     cout << ans[i] << " ";
    // cout << endl;
    // cout << endl;
    return ans;
}
void marwan() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= 12; i++) {
        vector<int> t = binexp(a, i);
        for (int j = 1; j <= n; j++)
            cout << t[j] << " ";
        cout << endl;
    }
    cout << endl;
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