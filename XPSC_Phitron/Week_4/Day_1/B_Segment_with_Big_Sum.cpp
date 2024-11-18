#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll l = 0, r = 0;
    bool flag = true;
    ll sum = v[0], count = LONG_LONG_MAX;
    while (l < n && r < n)
    {
        if (sum < s)
        {
            r++;
            if (r >= n)
                break;
            sum += v[r];
        }
        if (sum >= s)
        {
            flag = false;
            count = min(count, r - l + 1);
            sum -= v[l];
            l++;
        }
    }
    if (flag)
        cout << -1 << endl;
    else
        cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}