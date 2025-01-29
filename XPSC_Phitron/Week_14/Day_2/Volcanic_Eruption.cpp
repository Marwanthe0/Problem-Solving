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
    vector<int> v(n + 2);
    v[0] = INT_MAX, v[n + 1] = INT_MAX;
    vector<pair<int, int>> lava(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int temp = v[0];
    for (int i = 1; i <= n; i++)
    {
        if (!v[i])
        {
            temp = 0;
            continue;
        }
        temp = max(temp, v[i]);
        lava[i].first = temp;
    }
    temp = v[n + 1];
    for (int i = n; i >= 1; i--)
    {
        if (!v[i])
        {
            temp = 0;
            continue;
        }
        temp = max(temp, v[i]);
        lava[i].second = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
            cout << 0 << " ";
        else
            cout << (min(lava[i].first, lava[i].second) / k) + (min(lava[i].first, lava[i].second) % k != 0) << " ";
        // cout << lava[i].first << " " << lava[i].second << endl;
    }
    cout << endl;
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