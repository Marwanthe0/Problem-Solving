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
int mex(multiset<int> ms)
{
    int mx = 0;
    for (auto vl : ms)
    {
        if (vl >= mx)
        {
            mx++;
        }
    }
    return mx;
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    multiset<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][j] == 1)
            {
                x++;
            }
            else
            {
                break;
            }
        }
        ans.insert(x);
    }
    for (auto vl : ans)
        cerr << vl << " ";
    cerr << endl;
    cout << mex(ans) << endl;
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