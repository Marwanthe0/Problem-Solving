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
    vector<pair<int, int>> v(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(all(v));
    while (l < r)
    {
        int x = v[l].first, y = v[r].first;
        if (x + y == k)
        {
            cout << min(v[l].second, v[r].second) << " " << max(v[r].second, v[l].second) << endl;
            return;
        }
        else if (x + y < k)
            l++;
        else
            r--;
    }
    cout << "IMPOSSIBLE" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}