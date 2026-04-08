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
    cin >> n >> k;
    n = 2 * n + 1;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i < n - 1; i++) {
        if (v[i] - v[i - 1] > 1 && v[i] - v[i + 1] > 1 && k)
            v[i] = v[i] - 1, k--;
    }
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}