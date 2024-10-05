#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int par[N];
int group_size[N];
bool vis[N];
int dsu_find(int src)
{
    if (par[src] == -1)
        return src;
    int leader = dsu_find(par[src]);
    par[src] = leader;
    return leader;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {

        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class edges
{
public:
    int a, b, c;
    edges(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
bool cmp(edges a, edges b)
{
    return a.c < b.c;
}
void marwan()
{
    for (int i = 0; i < N; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        vis[i] = false;
    }
    int n, e;
    cin >> n >> e;
    vector<edges> v;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edges(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, removed = 0;
    for (auto ed : v)
    {
        int leaderA = dsu_find(ed.a);
        int leaderB = dsu_find(ed.b);
        vis[ed.a] = true;
        vis[ed.b] = true;
        if (leaderA == leaderB)
        {
            removed++;
        }
        else
        {
            dsu_union(ed.a, ed.b);
            cnt += ed.c;
        }
        // cout << ed.a << " " << ed.b << " " << ed.c << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "Not Possible" << endl;
            return;
        }
    }
    cout << removed << " " << cnt << endl;
}
int main()
{
    marwan();
    return 0;
}