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
    n *= 2;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    int sum = 0ll, sum1 = 0ll;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (i < (n / 2) + 1) {
            sum += v[i];
            a.push_back(v[i]);
        } else {
            sum1 += v[i];
            b.push_back(v[i]);
        }
    }
    sort(all(b));
    // for (auto vl : a)
    //     cerr << vl << " ";
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        cout << a[i] << " " << b[i] << " ";
    }
    cout << a[a.size() - 2] << " " << sum - sum1 << " " << a.back() << endl;
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