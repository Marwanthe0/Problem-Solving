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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    int sum = 0, neg = 0, mn = INT_MAX;
    for (auto &row : v)
        for (auto &vl : row)
        {
            cin >> vl;
            sum += abs(vl);
            mn = min(abs(vl), mn);
            if (vl <= 0)
                neg++;
        }
    if (neg & 1)
    {
        sum -= (2 * mn);
    }
    cout << sum << endl;
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