#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
        v[i] = s[i].size();
    }
    ll count = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum > m)
        {
            cout << i << endl;
            return;
        }
        else if (sum == m)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}