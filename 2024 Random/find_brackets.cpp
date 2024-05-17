#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    if ((a == b && b == c) && a % 2)
    {
        cout << -1 << endl;
        return;
    }
    int mn = min(a, min(b, c)), mx = max(a, max(b, c)), mid = ((a + b + c) - mn - mx);
    while (1)
    {
        if (mn <= 0 && mid <= 0)
            break;
        mx--, mid--;
        ans++;
        mn = min(mn, min(mx, mid)), mx = max(mn, max(mx, mid));
        mid = ((mn + mx + mid) - mn - mx);
    }
    cout << mn << " " << mid << " " << mx << " ans = " << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}