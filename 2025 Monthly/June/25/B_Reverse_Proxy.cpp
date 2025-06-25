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
    int k, n;
    cin >> k >> n;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 1; i <= k; i++)
        m[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (!v[i])
        {
            int mn = INT_MAX, idx = 1;
            for (auto [x, y] : m)
            {
                if (y < mn)
                    mn = y, idx = x;
            }
            cout << idx << " ";
            m[idx]++;
        }
        else
            m[v[i]]++, cout << v[i] << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}