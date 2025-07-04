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
    int a, b;
    cin >> a >> b;
    // cout << a << b << endl;
    // yes;
    if (b == 0)
    {
        // yes;
        cout << "Yes" << endl;
        return;
    }
    else if (a == 0)
    {
        // no;
        cout << "No" << endl;
        return;
    }
    else
    {
        if (b % a == 0)
            cout << "Yes" << endl;
        // yes;
        else
            cout << "No" << endl;
        // no;
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