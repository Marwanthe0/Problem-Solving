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
    set<int> s;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[0])
        {
            s.insert(i + 1);
        }
    }
    if (s.empty())
    {
        no;
        return;
    }
    yes;
    for (auto vl : s)
        cout << 1 << " " << vl << endl;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[0])
        {
            cout << *s.begin() << " " << i + 1 << endl;
        }
    }
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