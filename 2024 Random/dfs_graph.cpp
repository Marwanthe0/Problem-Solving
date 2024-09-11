#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> v[100000];
bool vis[100000];
void dfs(int src)
{
    cout << src << endl;
    vis[src] = true;
    for (auto child : v[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;
    dfs(src);
}
int main()
{
    marwan();
    return 0;
}