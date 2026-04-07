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
    int sp;
    cin >> sp;
    sp--;
    int x = v[sp];
    int l = 0, r = n - 1;
    bool flag = true;
    int count = 0;
    while (1) {
        while (l < sp && ((flag && v[l] == x) || (flag == false && v[l] != x)))
            l++;
        while (r > sp && (flag && v[r] == x) || (flag == false && v[r] != x)) {
            r--;
        }
        if (l == sp && r == sp)
            break;
        count++, flag = !flag;
    }
    cout << count + (!flag) << endl;
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