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
    // vector<vector<int>> v(n + 10, vector<int>(k + 10, 0));
    map<int, pair<vector<int>, vector<int>>> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            m[x].first.push_back(i);
            m[x].second.push_back(j);
        }
    }
    int ans = 0ll;
    for (auto &[x, y] : m)
    {
        // cout << x << endl;
        sort(all(y.first));
        sort(all(y.second));
        int l = 0, rem = y.first.size() - 1;
        for (int i = 0; i < y.first.size(); i++)
        {
            int ml = l - rem;
            ans += ((ml * y.first[i]) + (ml * y.second[i]));
            l++, rem--;
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}