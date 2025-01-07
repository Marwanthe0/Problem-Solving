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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    // for (auto &vl : v)
    //     cout << vl << " ";
    // cout << endl;
    ll med = n / 2, count = 1;
    while (med < n - 1 && k)
    {
        ll dif = v[med + 1] - v[med];
        dif *= count;
        if (dif >= k)
        {
            cout << v[med] + (k / count) << endl;
            return;
        }
        else
        {
            k -= dif;
            v[med] = v[med + 1];
            med++, count++;
        }
    }
    cout << v.back() + (k / count) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}