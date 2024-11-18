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
    ll sum = 0, count = 0;
    while (l < n && r < n)
    {
        sum += v[r];
        if (sum > s)
        {
            sum -= v[l];
            l++, r++;
        }
        else
            r++;
        count = max(count, r - l);
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}