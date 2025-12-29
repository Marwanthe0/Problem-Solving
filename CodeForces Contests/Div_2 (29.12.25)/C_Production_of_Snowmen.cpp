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
    vector<vector<int>> v(3, vector<int>(n, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            // int count = 0, flag = 1;
            // for (int x = 0; x < n; x++)
            // {
            //     int a = x, b = i + x, c = j + x;
            //     if (v[0][a] < v[1][b % n] && v[1][b % n] < v[2][c % n])
            //         count++;
            //     // else
            //     // {
            //     //     flag = 0;
            //     //     break;
            //     // }
            // }
            // if (flag)
            //     ans += count;
            int a = j, b = (j + i) % n;
            // cerr << (j % n) << " " << (j + i) << endl;
            // cout << v[1][a] << " " << v[2][b] << "::" << count << endl;
            if (v[1][a] < v[2][b])
                count++;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            d[i] = count;
        }
    }
    int mx = 0;
    int ans = 0;
    for (auto vl : d)
        if (vl)
            mx++;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            // int count = 0, flag = 1;
            // for (int x = 0; x < n; x++)
            // {
            //     int a = x, b = i + x, c = j + x;
            //     if (v[0][a] < v[1][b % n] && v[1][b % n] < v[2][c % n])
            //         count++;
            //     // else
            //     // {
            //     //     flag = 0;
            //     //     break;
            //     // }
            // }
            // if (flag)
            //     ans += count;
            int a = j, b = (j + i) % n;
            // cerr << (j % n) << " " << (j + i) << endl;
            // cout << v[1][a] << " " << v[2][b] << "::" << count << endl;
            if (v[0][a] < v[1][b])
                count++;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            // mx = max(mx, d[i]);
            ans += count * mx;
        }
    }
    // for (auto vl : d)
    //     cout << vl << " ";
    // cerr << endl;
    cout << ans << endl;
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