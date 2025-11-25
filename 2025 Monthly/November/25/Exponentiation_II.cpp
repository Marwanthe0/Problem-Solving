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
int ex(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b % 2 == 0)
    {
        return ((ex(a, b / 2) % M) * (ex(a, b / 2) % M)) % M;
    }
    else
        return ((a % M) * (ex(a, b - 1) % M)) % M;
}
void marwan()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << ex(a, ex(b, c)) << endl;
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