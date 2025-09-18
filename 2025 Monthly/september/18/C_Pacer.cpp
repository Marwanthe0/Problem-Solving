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
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        // cout << a << " " << b << endl;
        if ((max(a, b) % 2 != min(a, b) % 2) != (x % 2))
        {
            x++, k--;
        }
    }
    cout << k << endl;
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