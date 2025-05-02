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
    if (n == 1)
        cout << -1 << endl;
    else if (n & 1)
    {
        n /= 2;
        for (int i = 0; i < n; i++)
            cout
                << 1 << " ";
        for (int i = 0; i < n - 1; i++)
            cout << -1 << " ";
        cout << -2 << " " << 1 << endl;
    }
    else
    {
        n /= 2;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        for (int i = 0; i < n; i++)
            cout << -1 << " ";
        cout << endl;
    }
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