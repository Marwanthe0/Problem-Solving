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
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size())
    {
        swap(a, b);
    }
    int ans = a.size() + b.size();
    int mx = 0;
    // cerr << a << " " << b << endl;
    for (int i = 0; i < b.size(); i++)
    {
        int idx = i;
        for (int j = 0; j < a.size(); j++)
        {
            int count = 0, jdx = j;
            while (j < a.size() && i < b.size() && a[j] == b[i])
            {
                count++, i++, j++;
            }
            j = jdx;
            mx = max(count, mx);
            i = idx;
        }
    }
    cout << ans - (2 * mx) << endl;
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