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
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), t;
    for (auto &vl : v)
        cin >> vl;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        t.push_back(min(v[i], v[i + 1]));
        ans += t.back();
    }
    // cout << ans << endl;
    for (auto vl : t)
        cerr << vl << " ";
    cerr << endl;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1] = b;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}