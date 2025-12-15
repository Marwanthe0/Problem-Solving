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
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        yes;
        int sum = 0, sum2 = 0;
        for (int i = 2; i <= n; i += 2)
            cout << i << " ", sum += i;
        for (int i = 1; i <= n - 2; i += 2)
            cout << i << " ", sum2 += i;
        cout << sum - sum2;
        cout << endl;
    }
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