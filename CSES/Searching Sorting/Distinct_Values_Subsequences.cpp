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
int mod(int x, int m = M) { return x % M; }
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    int ans = 1ll;
    for (auto [_, x] : m)
        ans = mod(ans * 1ll * (x + 1));
    cout << ans - 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}