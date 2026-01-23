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
    int n, a, b, count = 0ll;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (vis[i] == 0 && vis[j] == 0)
            {
                if (v[i] <= min(a, b) && v[j] <= max(a, b))
                {
                    vis[i] = vis[j] = 1;
                    count++;
                }
            }
        }
    }
    cout << count << endl;
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