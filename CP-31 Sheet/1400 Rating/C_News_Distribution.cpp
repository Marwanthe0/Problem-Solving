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
int find(int x, vector<int> &par)
{
    if (x == par[x])
        return x;
    return par[x] = find(par[x], par);
}
void union_find(int a, int b, vector<int> &par, vector<int> &sz)
{
    a = find(a, par), b = find(b, par);
    if (a == b)
        return;
    if (a < b)
        swap(a, b);
    sz[a] += sz[b];
    par[b] = par[a];
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> par(n + 1, -1), sz(n + 1, 1);
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        vector<int> temp;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
            union_find(temp[0], x, par, sz);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // cerr << par[i] << " ";
        cout << sz[find(i, par)] << " ";
    }
    cout << endl;
    // cerr << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}