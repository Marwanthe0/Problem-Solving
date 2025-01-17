#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n + 1, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i].first += v[i - 1].first + x;
        v[i].second += v[i - 1].second + y;
    }
    for (int i = 1; i <= n; i++)
        cerr << v[i].first << " " << v[i].second << endl;
    cerr << endl;

    int ans = 4 * m;
    for (int i = 2; i <= n; i++)
    {
        ans += 4 * m;
        if (v[i].first < (v[i - 1].first + m))
            ans -= (2 * (v[i - 1].first + m - v[i].first));
        if (v[i].second < (v[i - 1].second + m))
            ans -= (2 * (v[i - 1].second + m - v[i].second));
    }
    cout << ans << endl;
}
int main()
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