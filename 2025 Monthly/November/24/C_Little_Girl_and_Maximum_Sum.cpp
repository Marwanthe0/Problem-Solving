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
    vector<int> v(n), t(n + 2, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        t[x]++, t[y + 1]--;
    }
    for (int i = 1; i <= n; i++)
        t[i] += t[i - 1];
    t.erase(t.begin());
    // for (auto vl : t)
    //     cout << vl << " ";
    sort(all(t), greater<int>());
    sort(all(v), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (v[i] * t[i]);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}