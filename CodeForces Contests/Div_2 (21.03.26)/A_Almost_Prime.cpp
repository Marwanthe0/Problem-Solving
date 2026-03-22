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
    vector<int> v(1e6 + 5, 0);
    for (int i = 2; i <= 1e6; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= 1e6; j += i) {
                v[j]++;
            }
        }
    }
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] == 2)
            count++;
    cout << count << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}