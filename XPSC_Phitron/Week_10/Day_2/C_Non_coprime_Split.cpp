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
void marwan()
{
    ll l, r;
    cin >> l >> r;
    if (l <= 2 && r <= 3)
    {
        cout << -1 << endl;
        return;
    }
    if (r - l >= 1)
    {
        for (ll i = l; i <= r; i++)
        {
            if (i % 2 == 0 && i != 2)
            {
                cout << (i / 2) << " " << (i / 2) << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
    else if (r % 2 == 0)
    {
        cout << (r / 2) << " " << (r / 2) << endl;
        return;
    }
    else
    {
        for (ll i = 2; (i * i) <= r; i++)
        {
            if (r % i == 0)
            {
                cout << i << " " << r - i << endl;
                return;
            }
        }
        cout << -1 << endl;
    }
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