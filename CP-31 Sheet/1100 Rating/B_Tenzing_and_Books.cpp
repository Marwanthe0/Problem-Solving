#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    int ans = 0;
    // taking or for only those values where 1 does not appear for the 0 bits positions in k, otherwise stopping
    for (int i = 0; i < 3; i++)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if ((x & (~k)) != 0)
            {
                flag = false;
            }
            if (flag)
                ans |= x;
        }
    }
    if (ans == k)
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