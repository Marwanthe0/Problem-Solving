#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    for (auto &row : v)
    {
        for (auto &vl : row)
            cin >> vl;
        sort(all(row));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] - v[i][j - 1] != n)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    vector<pair<int, int>> last(n);
    for (int i = 0; i < n; i++)
    {
        last[i] = {v[i][0], i + 1};
    }
    sort(all(last));
    for (auto vl : last)
        cout << vl.second << " ";
    cout << endl;
}
int main()
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