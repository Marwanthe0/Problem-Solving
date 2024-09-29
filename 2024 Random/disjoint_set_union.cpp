#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int par[100005];
int groupsize[100005];
int find(int leader)
{
    if (par[leader] == -1)
        return leader;
    int ld = find(par[leader]);
    par[leader] = ld;
    return ld;
}
void dsu(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);
    if (groupsize[leaderA] > groupsize[leaderB])
    {
        par[leaderB] = leaderA;
        groupsize[leaderA] += groupsize[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        groupsize[leaderB] += groupsize[leaderA];
    }
}
void marwan()
{
    for (int i = 0; i < 100005; i++)
    {
        par[i] = -1;
        groupsize[i] = 1;
    }
    int n, k;
    cin >> n >> k;
    vecto
    cout << flag << endl;
}
int main()
{
    marwan();
    return 0;
}