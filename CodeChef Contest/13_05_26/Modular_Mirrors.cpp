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
    int n, m;
    cin >> n >> m;
    if ((n - 2) % 3 == 0) {
        int x = 1, y = m - 1;
        vector<int> ans;
        for (int i = 0; i <= ((n - 2) / 3); i++) {
            if (i % 2 == 0) {
                ans.push_back(x);
                ans.push_back(x);
            } else {
                ans.push_back(y);
                ans.push_back(y);
            }
            ans.push_back(0);
        }
        if (ans.back() == 0)
            ans.pop_back();
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