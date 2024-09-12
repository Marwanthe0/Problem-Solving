#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
int parentarr[N];
bool cycle;
void dfs(int par)
{
    vis[par] = true;
    for (auto child : v[par])
    {
        if (vis[child] && parentarr[par] != child)
            cycle = true;
        if (!vis[child])
        {
            parentarr[child] = par;
            dfs(child);
        }
    }
}
void marwan()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cycle = false;
    int src;
    cin >> src;
    dfs(src);
    if (cycle)
        yes;
    else
        no;
}
int main()
{
    marwan();
    return 0;
}