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
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    int ans = 0ll;
    if (k & 1)
        k = 1;
    else
        k = 2;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i != n - 1)
            ans += k * v[i];
    }
    ans += v.back();
    if (ans & 1)
        cout << "odd" << endl;
    else
        cout << "even" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}