#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, e;
    cin >> n >> e;
    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0;
        }
    }
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u][v] = c;
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && adj [i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    bool neg = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
            if (i == j && adj[i][j] != 0)
                neg = true;
        }
        cout << endl;
    }
    if (neg)
        cout << "Negative Cycle Detected\n";
    else
    {
        int src;
        cin >> src;
        src--;
        int t;
        cin >> t;
        while (t--)
        {
            int x;
            cin >> x;
            x--;
            cout << adj[src][x] << endl;
        }
    }
}
int main()
{
    marwan();
    return 0;
}