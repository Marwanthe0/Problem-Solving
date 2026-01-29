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
int pw(int a, int b)
{
    if (b == 0)
        return 1;
    if (b & 1)
        return (a * 1ll * (pw(a, b - 1)));
    return (pw(a, b / 2)) * 1ll * (pw(a, b / 2));
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    int c2 = 0, c5 = 0, t1 = n, t2 = n;
    while (t1 % 2 == 0)
    {
        c2++;
        t1 /= 2;
    }
    while (t2 % 5 == 0)
    {
        c5++;
        t2 /= 5;
    }
    // cerr << c2 << " " << c5 << endl;
    for (int i = 17; i >= 0; i--)
    {
        int x = max(0ll, i - c2), y = max(0ll, i - c5);
        x = pw(2, x), y = pw(5, y);
        if (x > k || y > k)
            continue;
        int xy = x * 1ll * y;
        if (k < xy)
            continue;
        cout << (k - (k % xy)) * 1ll * n << endl;
        return;
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
    // cout << pw(5, 18) << endl;
    return 0;
}