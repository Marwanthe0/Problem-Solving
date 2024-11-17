#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x)
            v.push_back(x);
        sum += abs(x);
    }
    n = v.size();
    ll l = 0, r = 0, count = 0;
    for (ll i = 0; i < n; i++)
    {

        if (v[i] < 0)
        {
            count++;
            while (i < n && v[i] < 0)
                i++;
        }
        else
        {
            while (i < n && v[i] > 0)
                i++;
        }
    }
    cout << sum << " " << count << endl;
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