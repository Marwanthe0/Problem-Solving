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
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
        v.push_back(x);
    }
    sort(all(v));
    map<pair<int, int>, int> mp2;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        mp[{a, b}] = c;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (mp2.find({v[i], v[j]}))
            {
                mp[mp[]]
            }
        }
    }
    cout << m.size() << endl;
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