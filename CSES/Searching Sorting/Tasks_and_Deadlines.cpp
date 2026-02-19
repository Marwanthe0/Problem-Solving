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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    sort(all(v));
    int ans = 0, sum = 0;
    for (auto [x, y] : v)
    {
        sum += x;
        ans += y - sum;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}