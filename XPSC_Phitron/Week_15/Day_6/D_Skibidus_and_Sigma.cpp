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
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b) { return a.first > b.first; }
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, vector<int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m);
        for (auto &vl : temp)
            cin >> vl;
        int sum = 0ll, cnt = n;
        for (int i = 0; i < m; i++)
        {
            sum += (temp[i] * n);
        }
        v[i].first = sum, v[i].second = temp;
    }
    sort(all(v), cmp);
    int ans = 0ll, x = n * m;
    for (auto row : v)
    {
        for (auto vl : row.second)
        {
            ans += (x * vl);
            x--;
        }
    }
    cout << ans << endl;
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