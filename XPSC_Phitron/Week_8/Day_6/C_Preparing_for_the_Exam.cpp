#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), b(k);
    for (auto &vl : a)
    {
        cin >> vl;
    }
    for (auto &vl : b)
        cin >> vl;
    if (n - k > 1)
    {
        for (ll i = 0; i < m; i++)
            cout << '0';
        cout << endl;
        return;
    }
    sort(b.begin(), b.end());
    ll una = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (i > k || (i != b[i - 1]))
        {
            una = i;
            break;
        }
    }
    if (una == -1)
    {
        for (ll i = 0; i < m; i++)
            cout << '1';
        cout << endl;
        return;
    }
    for (ll i = 0; i < m; i++)
    {
        if (a[i] == una)
            cout << '1';
        else
            cout << '0';
    }
    cout << endl;
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