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
void bfs(int par)
{
    queue<int> q;
    q.push(par);
    vis[par] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto child : v[parent])
        {
            if (vis[child] && parentarr[parent] != child)
            {
                cycle = true;
            }
            if (!vis[child])
            {
                vis[child] = true;
                q.push(child);
                parentarr[child] = parent;
            }
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
    bfs(src);
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