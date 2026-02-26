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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    vector<unordered_map<int, int>> ts(n);
    vector<vector<int>> temp(n), temp2(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
        reverse(all(v[i]));
        for (auto vl : v[i])
        {
            if (!ts[i].count(vl))
            {
                temp[i].push_back(vl);
            }
            ts[i][vl]++;
        }
        v[i] = temp[i];
    }
    sort(all(v));
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (auto vl : v[i])
        {
            cout << vl << " ";
            s.insert(vl);
        }
        int mx = i + 1;
        for (int j = i + 1; j < n; j++)
        {
            vector<int> tt;
            for (auto vl : v[j])
            {
                if (!s.count(vl))
                    tt.push_back(vl);
            }
            v[j] = tt;
            if (v[j] < v[mx])
                mx = j;
        }
        if (i + 1 < n)
            swap(v[i + 1], v[mx]);
    }
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