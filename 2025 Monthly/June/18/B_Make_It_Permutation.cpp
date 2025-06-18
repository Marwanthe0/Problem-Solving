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
    cout << 3 + (2 * (n - 3)) << endl;
    cout << 1 << " " << 1 << " " << n << endl;
    cout << 2 << " " << 2 << " " << n << endl;
    for (int i = 3; i < n; i++)
    {
        // cout << i << " " << 1 << " " << n << endl;
        cout << i << " " << 1 << " " << i - 1 << endl;
        cout << i << " " << i << " " << n << endl;
    }
    cout << n << " " << 1 << " " << n - 1 << endl;
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