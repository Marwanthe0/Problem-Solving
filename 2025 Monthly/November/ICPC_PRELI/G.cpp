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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = 0; j < m; j++)
        {
            // cerr << v[i][j] << " ";
            r ^= v[i][j];
        }
        row[i] = r;
        // cerr << endl;
    }
    for (int j = 0; j < m; j++)
    {
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c ^= v[i][j];
        }
        col[j] = c;
    }
    // for (auto vl : row)
    //     cout << vl << " ";
    // cout << endl;
    // for (auto vl : col)
    //     cout << vl << " ";
    // cout << endl;
    int tsum = accumulate(all(row), 0ll) + accumulate(all(col), 0ll);
    pair<int, int> ans = {0, 0};
    int mx = INT_MIN, ansvl = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = row[i] + col[j];
            // cout << i << " " << j << "::" << sum << "--";
            int newvl = row[i] ^ v[i][j], newcl = col[j] ^ v[i][j]; // 21 20
            int new2 = (col[j] ^ v[i][j]) ^ newvl, newcol2 = (row[i] ^ v[i][j]) ^ newcl;
            int new_sum = 0 + new2, new_sum2 = 0 + newcol2;
            // cout << new_sum << endl;
            if ((sum - new_sum) > mx)
            {
                ans = {i, j};
                mx = sum - new_sum;
                ansvl = newvl;
            }
            if (sum - new_sum2 > mx)
            {
                ans = {i, j};
                mx = sum - new_sum2;
                ansvl = newcl;
            }
        }
    }

    v[ans.first][ans.second] = ansvl;
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = 0; j < m; j++)
        {
            // cerr << v[i][j] << " ";
            r ^= v[i][j];
        }
        row[i] = r;
        // cerr << endl;
    }
    for (int j = 0; j < m; j++)
    {
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c ^= v[i][j];
        }
        col[j] = c;
    }
    tsum = accumulate(all(row), 0ll) + accumulate(all(col), 0ll);
    cout << tsum << endl;
    // cout << endl;
    // cout << ans.first << " " << ans.second << endl;
    // cout << tsum << endl;
    // cout << endl;
    // cerr << endl;
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