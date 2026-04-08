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
    vector<int> v(n + 1);
    v[0] = -1;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(all(v));
    set<int> ans;
    int x = (n / 2) + (n % 2);
    ans.insert(v[x]);
    int l = x - 1, r = x + 1;
    for (int i = 0; i < k; i++) {
        if (i & 1) {
            ans.insert(v[((n & 1) ? r++ : l--)]);
        } else
            ans.insert(v[((n & 1) ? l-- : r++)]);
    }
    for (auto vl : ans)
        cout << vl << " ";
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