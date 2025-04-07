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
    vector<vector<int>> v(n);
    for (auto &row : v)
    {
        string x;
        cin >> x;
        for (auto c : x)
            row.push_back(c - '0');
    }
    vector<vector<int>> t = v, k = v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pair<int, int> a = {j, n - i - 1}, b = {n - i - 1, n - j - 1}, c = {n - j - 1, n - (n - i - 1) - 1};
            // cout << i << ":" << j << "(";
            // cout << a.first << ":" << a.second << "  " << b.first << ":" << b.second << "  " << c.first << ":" << c.second << ")   ";
        }
        // cout << endl;
    }
    int count = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0, cnt2 = 0;
            pair<int, int> a = {j, n - i - 1}, b = {n - i - 1, n - j - 1}, c = {n - j - 1, n - (n - i - 1) - 1};
            // if (t[i][j] == t[a.first][a.second] && t[i][j] == t[b.first][b.second] && t[i][j] == t[c.first][c.second])
            //     continue;
            if (t[i][j] == 1)
            {
                if (t[i][j] != t[a.first][a.second])
                    cnt++;
                if (t[i][j] != t[b.first][b.second])
                    cnt++;
                if (t[i][j] != t[c.first][c.second])
                    cnt++;
                if (cnt >= 2)
                    count++;
            }
            else
            {
                if (t[i][j] != t[a.first][a.second])
                    cnt2++;
                if (t[i][j] != t[b.first][b.second])
                    cnt2++;
                if (t[i][j] != t[c.first][c.second])
                    cnt2++;
                if (cnt2 >= 2)
                    count2++;
            }
        }
    }
    cout << count << " " << count2 << endl;
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