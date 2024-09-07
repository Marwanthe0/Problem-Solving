#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<int> v[1005];
bool vis[1005];
int lev[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    lev[src] = 0;
    cout << src << " " << lev[src] << endl;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        vis[par] = true;
        for (auto vl : v[par])
        {
            if (vis[vl] == false)
            {
                q.push(vl);
                vis[vl] = true;
                lev[vl] = lev[par] + 1;
                cout << vl << " " << lev[vl] << endl;
            }
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
    bfs(src);
}
int main()
{
    marwan();
    return 0;
}