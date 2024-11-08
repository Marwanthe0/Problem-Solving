#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (!m.count(u))
        {
            m[u].first = i;
            m[u].second = i;
        }
        else
            m[u].second = i;
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!m.count(a) or !m.count(b) or m[a].first > m[b].second)
        {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
    }
}
int main()
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