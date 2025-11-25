#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> ans(N, 0);
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
            ans[j]++;
    }
}
void marwan()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}