#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
int find(int x, vector<int> &par)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x], par);
}
void un(int a, int b, vector<int> &par)
{
    a = find(a, par), b = find(b, par);
    if (a == b)
        return;
    if (a < b)
        swap(a, b);
    par[b] = par[a];
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), par(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i <= n; i++)
        par[i] = i;
        
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