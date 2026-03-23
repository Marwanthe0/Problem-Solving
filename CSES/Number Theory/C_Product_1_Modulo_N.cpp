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
void marwan() {
    int n;
    cin >> n;
    vector<int> ans;
    int x = 1;
    for (int i = 1; i < n; i++) {
        if (__gcd(i, n) == 1) {
            ans.push_back(i);
            x = (x * 1ll * i) % n;
        }
    }
    if (x == n - 1 && n != 2)
        ans.pop_back();
    cout << ans.size() << endl;
    for (auto &vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}