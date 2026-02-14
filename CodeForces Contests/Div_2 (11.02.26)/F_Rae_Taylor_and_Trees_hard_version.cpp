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
int find(int n, vector<int> &par)
{
    return ((par[n] == n) ? n : par[n] = find(par[n], par));
}
void dsunion(int a, int b, vector<int> &par)
{
    a = find(a, par), b = find(b, par);
    if (a == b)
        return;
    if (a > b)
        swap(a, b);

    par[b] = par[a];
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), par(n + 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    int mn = INT_MAX;
    set<int> s;
    vector<pair<int, int>> edges;
    for (auto &vl : v)
    {
        cin >> vl;
        set<int> check;
        for (auto val : s)
        {
            if (val < vl && find(val, par) != find(vl, par))
            {
                dsunion(vl, val, par);
                check.insert(max(vl, val));
                edges.push_back({vl, val});
            }
            else if (val >= vl)
                break;
        }
        for (auto val : check)
            s.erase(val);
        s.insert(vl);
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = find(i, par);
        if (par[i] != par[1])
        {
            no;
            return;
        }
    }
    yes;
    for (auto [x, y] : edges)
        cout << x << " " << y << endl;
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