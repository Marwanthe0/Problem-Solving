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
    vector<ll> v(n), even, odd;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] % 2)
        {
            odd.push_back(v[i]);
        }
        else
            even.push_back(v[i]);
    }
    if (odd.size() == 0 || even.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<ll>());
        ll count = 0, temp = *odd.begin();
        auto it = even.begin();
        if (temp < *it)
        {
            count++;
            temp += *it;
        }
        while (it != even.end())
        {
            temp += *it;
            count++, it++;
            if (it != even.end() && temp < *it)
            {
                temp += *it;
                count++;
            }
        }
        cout << min(count, (ll)(even.size() + 1)) << endl;
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