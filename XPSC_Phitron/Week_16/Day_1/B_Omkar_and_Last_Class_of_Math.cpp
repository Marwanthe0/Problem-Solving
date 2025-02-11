#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v;
    if (n % 2 == 0)
    {
        cout << n / 2 << " " << n / 2 << endl;
        return;
    }
    for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
                v.push_back(n / i);
        }
    }
    sort(all(v));
    int ans = INT_MAX, f, l;
    for (auto vl : v)
    {
        int x = n - vl;
        if (x == 0 || vl == 0)
            continue;
        if ((x * vl) / __gcd(x, vl) < ans)
        {
            ans = (x * vl) / __gcd(x, vl);
            f = min(x, vl), l = max(x, vl);
        }
    }
    cout << f << " " << l << endl;
}
int32_t main()
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