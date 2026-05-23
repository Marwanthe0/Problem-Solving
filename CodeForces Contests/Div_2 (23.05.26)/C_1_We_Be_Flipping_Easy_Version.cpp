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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    bool flag = true;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (flag) {
            if (v[i] > 0) {
                ans.push_back(i + 1);
                flag = false;
            }
        } else {
            if (v[i] < 0) {
                ans.push_back(i + 1);
                flag = true;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &vl : ans)
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