#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000009
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<ll> vis(N, 0);
void sieve()
{
    for (ll i = 2; (i * i) < N; i++)
    {
        if (!vis[i])
        {
            for (ll j = i * i; j < N; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
    {
        cin >> vl;
        if ((ll)vl == 1ll)
        {
            no;
            continue;
        }
        ll x = sqrt(vl);
        if (x * x == (ll)vl && (!vis[sqrt((ll)vl)]))
            yes;
        else
            no;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    marwan();
    return 0;
}