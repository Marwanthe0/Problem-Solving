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
    int n, m;
    cin >> n >> m;
    double a = 100, b = 225;
    // if ((n * (1.0) / (1.0) * a) > (m * (1.0) / b * (1.0)))
    //     cout << "Small" << endl;
    // else if ((n * (1.0) / (1.0) * a) < (m * (1.0) / a * (1.0)))
    //     cout << "Large" << endl;
    // else
    //     cout << "Equal" << endl;
    if (n * b < m * a)
        cout << "Small" << endl;
    else if (n * b > m * a)
        cout << "Large" << endl;
    else
        cout << "Equal" << endl;
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