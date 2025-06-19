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
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int first = (k - a) / x + ((k - a) % x != 0), second = (k - b) / y + ((k - b) / y != 0);
    cout << max({0ll, first, second}) << endl;
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