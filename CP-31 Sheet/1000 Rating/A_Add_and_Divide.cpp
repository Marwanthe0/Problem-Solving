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
int lg(int a, int n)
{
    int count = 0;
    while (a)
        a /= n, count++;
    return count;
}
void marwan()
{
    int a, b, ans = INT_MAX;
    cin >> a >> b;
    for (int i = max(2ll, b); i <= b + 10000; i++)
    {
        int uttor = lg(a, i);
        ans = min(uttor + (i - b), ans);
    }
    cout << ans << endl;
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