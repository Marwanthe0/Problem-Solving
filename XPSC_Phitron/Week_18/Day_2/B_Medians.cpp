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
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1)
    {
        cout << 1 << endl
             << 1 << endl;
        return;
    }
    if (((k - 1) % 2 == 0) || ((n - k) % 2 == 0))
    {
        cout << -1 << endl;
        return;
    }
    cout << 3 << endl;
    cout << 1 << " " << k << " " << k + 1 << endl;
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