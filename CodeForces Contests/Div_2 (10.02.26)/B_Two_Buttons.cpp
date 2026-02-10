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
int f(int n, int k)
{
    if (n == k)
        return 0;
    int ml = INT_MAX, sub = INT_MAX;
    if (n < k)
        ml = 1 + f(n * 2, k);
    else
        sub = 1 + f(--n, k);
    return min(ml, sub);
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    cout << f(n, k) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}