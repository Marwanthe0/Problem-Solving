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
    vector<ll> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    ll dif = LONG_LONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            no;
            return;
        }
        if (a[i] - b[i] > dif)
            dif = a[i] - b[i];
    }
    for (auto &vl : a)
        vl -= dif;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] && a[i] != b[i])
        {
            no;
            return;
        }
    }
    yes;
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