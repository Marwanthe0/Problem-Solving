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
bool hit(int n, int a, int b)
{
    if (n <= 0)
        return true;
    if (b <= 0)
        return false;
    else if (a > 0 && b > 0)
        return (hit((n / 2) + 10, a - 1, b) || hit(n - 10, a, b - 1));
    else if (b > 0)
        return hit(n - b * 10, a, 0);
}
void marwan()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (hit(n, a, b))
        yes;
    else
        no;
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