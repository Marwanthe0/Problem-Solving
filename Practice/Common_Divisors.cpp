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
    vector<int> v(n), vis(N + 1, 0);
    for (auto &vl : v) {
        cin >> vl;
        vis[vl]++;
    }
    int mx = *max_element(all(v));
    for (int i = mx; i >= 1; i--) {
        int count = 0;
        for (int j = i; j <= mx; j += i) {
            count += vis[j];
        }
        if (count >= 2) {
            cout << i << endl;
            return;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}