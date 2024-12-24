#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> vec(n);
    ll sum = 0;

    for (auto &it : vec)
    {
        cin >> it;
        sum += it;
    }

    sort(all(vec));

    ll cnt = 0;

    for (int i = 0; i < n; i++)
    {
        ll lower = sum - y - vec[i];
        ll upper = sum - x - vec[i];

        int l = lower_bound(vec.begin() + i + 1, vec.end(), lower) - vec.begin();
        int u = upper_bound(vec.begin() + i + 1, vec.end(), upper) - vec.begin();

        cnt += (u - l);
    }

    cout << cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}