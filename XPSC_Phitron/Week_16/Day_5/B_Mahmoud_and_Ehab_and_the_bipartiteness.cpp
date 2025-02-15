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
vector<int> v[100005];
int cnt[2] = {0};
void dfs(int node, int pnode, int color)
{
    cnt[color]++;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (v[node][i] != pnode)
            dfs(v[node][i], node, !color);
    }
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    cout << cnt[0] * cnt[1] - n + 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}