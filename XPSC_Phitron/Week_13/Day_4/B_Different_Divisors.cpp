#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
vector<bool> vis(N + 9, 0);
vector<ll> prime;
void sieve()
{
    for (ll i = 2; (i * i) <= N; i++)
    {
        if (!vis[i])
        {
            for (ll j = i + i; j <= N; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (ll i = 2; i <= N; i++)
        if (!vis[i])
            prime.push_back(i);
}
void marwan()
{
    ll n;
    cin >> n;
    ll x = 1, ans = 1, i = 0;
    while (prime[i] - x < n)
    {
        i++;
    }
    ans *= prime[i];
    x = prime[i];
    while (prime[i] - x < n)
    {
        i++;
    }
    ans *= prime[i];
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    // for (auto vl : prime)
    //     cout << vl << " ";
    // cout << endl;
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}