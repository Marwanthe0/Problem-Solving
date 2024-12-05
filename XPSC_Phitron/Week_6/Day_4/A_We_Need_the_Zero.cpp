#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int x = v[0];
    for (int i = 1; i < n; i++)
    {
        x ^= v[i];
    }
    ll ans = 0;
    for (auto &vl : v)
    {
        vl ^= x;
        ans ^= vl;
    }
    if (ans)
        cout << -1 << endl;
    else
        cout << x << endl;
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