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
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x % k]++;
    }
    for (auto vl : m)
        cerr << vl.first << " ";
    cerr << endl;
    for (auto vl : a)
    {
        int x = (vl % k);
        int y = abs((k - x)) % k;
        if (m.find(x) != m.end())
        {
            m[x]--;
            if (m[x] <= 0)
                m.erase(x);
        }
        else if (m.find(y) != m.end())
        {
            m[y]--;
            if (m[y] <= 0)
                m.erase(y);
        }
    }
    if (m.empty())
        yes;
    else
        no;
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