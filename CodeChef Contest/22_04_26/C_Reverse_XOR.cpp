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
    if (n == 0) {
        yes;
        return;
    }
    while (n % 2 == 0)
        n >>= 1;
    vector<int> v;
    int x = __lg(n);
    for (int i = x; i >= 0; i--) {
        v.push_back(1 & (n >> i));
    }
    int l = 0, r = v.size() - 1;
    if ((v.size() & 1) && v[v.size() / 2]) {
        no;
        return;
    }
    while (l <= r) {
        if (v[l] != v[r]) {
            no;
            return;
        }
        l++, r--;
    }
    yes;
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