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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &row : v)
        for (auto &vl : row)
            cin >> vl;
    vector<int> a;
    for (int i = 0; i < n; i++)
        a.push_back(v[0][i]);
    for (int i = 1; i < n; i++)
        a.push_back(v[i][n - 1]);
    n *= 2;
    cout << ((n * (n + 1)) / 2) - accumulate(all(a), 0ll) << " ";
    for (auto vl : a)
        cout << vl << " ";
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