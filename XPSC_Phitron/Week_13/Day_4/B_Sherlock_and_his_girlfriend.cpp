#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 100009
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<bool> vis(N + 9, 0);
void sieve()
{
    for (ll i = 2; (i * i) <= N; i++)
    {
        if (!vis[i])
        {
            for (ll j = i + i; j <= N; j += i)
                vis[j] = 1;
        }
    }
}
void marwan()
{
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 2; i <= n + 1; i++)
    {
        if (!vis[i])
            m[1]++;
        else
            m[2]++;
    }
    cout << m.size() << endl;
    for (ll i = 2; i <= n + 1; i++)
    {
        if (!vis[i])
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    marwan();
    return 0;
}