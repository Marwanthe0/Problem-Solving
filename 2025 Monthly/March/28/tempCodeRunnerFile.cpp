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
    vector<vector<int>> p;
    int g = v[0];
    for (auto vl : v)
    {
        g = __gcd(vl, g);
        vector<int> t;
        for (int i = 2; i < vl; i++)
        {
            while (vl % i == 0)
            {
                t.push_back(i);
                vl /= i;
            }
        }
        if (vl != 1)
            t.push_back(vl);
        p.push_back(t);
    }
    // for (auto row : p)
    // {
    //     for (auto vl : row)
    //         cout << vl << " ";
    //     cout << endl;
    // }
    for (auto &vl : v)
        vl /= g;
    // cout << endl;
    for (int i = 2; i <= 1000; i++)
    {
        map<int, int> m;
        for (auto vl : v)
            m[vl % i]++;
        if (m.size() == 2)
        {
            cout << i << " g" << endl;
            return;
        }
    }
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