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
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    sort(all(v));
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (v[l].first + v[r].first == k)
        {
            cout << v[l].second << " " << v[r].second << endl;
            return;
        }
        else if (v[l].first + v[r].first > k)
            r--;
        else
            l++;
    }
    cout << "IMPOSSIBLE" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}