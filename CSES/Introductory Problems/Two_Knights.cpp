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
int f(int n)
{
    if (n == 1)
        return 0;
    int x = n * n;
    int ans = (x * (x - 1)) / 2;
    if (n > 2)
        ans -= 2 * (n - 2) * 1ll * (n - 1);
    ans -= 2 * (n - 2) * 1ll * (n - 1);
    return ans;
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << f(i) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}