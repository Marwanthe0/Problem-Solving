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
int lcm(int a, int b) { return (a * b) / __gcd(a, b); }
void marwan() {
    int n;
    cin >> n;
    int count = 0;
    vector<int> v(n), b(n);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    if (__gcd(v[0], v[1]) < b[0] && __gcd(v[0], v[1]) != v[0])
        v[0] = __gcd(v[0], v[1]), count++;
    for (int i = 1; i < n - 1; i++) {
        int x = v[i];
        int temp = lcm(__gcd(v[i], v[i - 1]), __gcd(v[i], v[i + 1]));
        if (temp < b[i])
            v[i] = temp;
        if (x != v[i]) {
            count++;
            // cerr << i << " " << v[i] << endl;
        }
    }
    // cerr << endl;
    if (__gcd(v[n - 1], v[n - 2]) < b[n - 1] && __gcd(v[n - 1], v[n - 2]) != v[n - 1])
        v[n - 1] = __gcd(v[n - 1], v[n - 2]), count++;
    cout << count << endl;
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