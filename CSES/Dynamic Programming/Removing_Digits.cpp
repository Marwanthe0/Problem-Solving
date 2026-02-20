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
    int mx = 0;
    while (n)
        mx = max(mx, n % 10), n /= 10;
    return mx;
}
void marwan()
{
    int n, count = 0;
    cin >> n;
    while (n)
    {
        n -= f(n);
        count++;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}