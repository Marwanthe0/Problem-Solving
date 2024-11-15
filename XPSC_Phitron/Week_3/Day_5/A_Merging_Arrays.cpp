#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    ll l = 0, r = 0;
    a.push_back(INT_MAX);
    b.push_back(INT_MAX);
    while (l < n || r < m)
    {
        if (a[l] < b[r])
            cout << a[l++] << " ";
        else
            cout << b[r++] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}