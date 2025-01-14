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
    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    vector<ll> temp;
    for (ll i = 1;; i++)
    {
        temp = v;
        bool flag = true;
        for (ll j = i; j >= 1; j--)
        {
            auto it = lower_bound(all(temp), j);
            if ((it == temp.begin() && *it != j))
            {
                flag = false;
                break;
            }
            else
            {
                if (it == temp.end() || *it != j)
                    --it;
                temp.erase(it);
            }
            temp[0] += j;
            sort(all(temp));
        }
        if (flag)
        {
            ans = i;
        }
        else
            break;
    }
    cout << ans << endl;
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