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
    vector<int> a(k);
    vector<pair<int, int>> b(n);
    for (auto &vl : a)
        cin >> vl;
    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    sort(all(b));
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        int x = (k + 1) - b[i].first;
        while (x--) {
            ans.push_back(b[i].second);
        }
    }
    if (ans.size() <= 1000) {
        cout << ans.size() << endl;
        for (auto vl : ans)
            cout << vl << " ";
        cout << endl;
    } else
        minus;
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