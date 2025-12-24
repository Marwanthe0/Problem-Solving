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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int mn = n - 2, mx = n - 1;
    vector<vector<int>> ans;
    for (int i = n - 3; i >= 0; i--)
    {
        vector<int> temp;
        if (v[i] > v[i + 1])
        {
            if (v[mn] - v[mx] < v[i])
            {
                v[i] = v[mn] - v[mx];
                temp.push_back(i + 1);
                temp.push_back(mn + 1);
                temp.push_back(mx + 1);
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        if (v[i] < v[mn])
            mn = i;
        if (v[i] > v[mx])
            mx = i;
        if (temp.size())
        {
            ans.push_back(temp);
        }
    }
    if (is_sorted(all(v)))
    {
        cout << ans.size() << endl;
        for (auto row : ans)
        {
            for (auto vl : row)
                cout << vl << " ";
            cout << endl;
        }
    }
    else
        cout << -1 << endl;
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