#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for (ll i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
            v.push_back(i);
        if ((n / i) != i)
            v.push_back(n / i);
    }
    sort(v.begin(), v.end());
    if (v.size() < k)
        cout << -1 << endl;
    else
        cout << v[k - 1] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}