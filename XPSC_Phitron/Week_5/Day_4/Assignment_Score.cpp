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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll x = (n + 1) * 50;
    if ((x - sum) > 100)
        cout << -1 << endl;
    else if ((x - sum) < 0)
        cout << 0 << endl;
    else
        cout << x - sum << endl;
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