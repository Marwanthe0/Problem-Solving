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
    int n, k;
    cin >> n >> k;
    int l = 1, r = n, ans, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        int x = ((mid * (mid + 1)) / 2) - (n - mid);
        if (x == k)
        {
            cout << n - mid << endl;
            return;
        }
        else if (x < k)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}