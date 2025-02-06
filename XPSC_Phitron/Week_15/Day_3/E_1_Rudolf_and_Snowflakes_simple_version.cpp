#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int ans[N];
void bakhor()
{
    for (int i = 2; i < N; i++)
    {
        int x = i * i, y = (i) + 1;
        for (int j = y;;)
        {
            j += x;
            if (j >= N)
                break;
            ans[j]++;
            x *= i;
        }
    }
}
void marwan()
{
    int n;
    cin >> n;
    if (ans[n])
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(ans, 0, sizeof(ans));
    bakhor();
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}