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
int bd(int n)
{
    int count = 0;
    while (n != 0)
        n /= 2, count++;
    return count;
}
void marwan()
{
    int n, m, a, b, count = 0;
    cin >> n >> m >> a >> b;
    cout << bd(min(a, n - a)) + bd(min(b, m - b)) << endl;
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