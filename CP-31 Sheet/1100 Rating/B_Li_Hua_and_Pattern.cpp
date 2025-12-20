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
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (auto &row : v)
    {
        for (auto &vl : row)
            cin >> vl;
    }
    if (n == 1)
    {
        yes;
        return;
    }
    int li = n - 1, count = 0;
    for (int i = 0; i < n; i++, li--)
    {
        int lj = n - 1;
        for (int j = 0; j < n; j++, lj--)
        {

            if (v[i][j] != v[li][lj])
            {
                count++;
            }
        }
    }
    count /= 2;
    // cout << count << endl;
    if (k >= count && ((k - count) % 2 == 0 || ((n & 1))))
        yes;
    else
        no;
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