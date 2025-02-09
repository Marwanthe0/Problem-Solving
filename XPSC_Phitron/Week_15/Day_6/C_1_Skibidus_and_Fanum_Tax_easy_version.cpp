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
    vector<int> a(n), b(m), c;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (auto vl : a)
        c.push_back(b[0] - vl);
    vector<int> ans;
    ans.push_back(min(a.front(), c.front()));
    yes;
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