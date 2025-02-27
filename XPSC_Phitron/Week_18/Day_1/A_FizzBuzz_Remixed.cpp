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
    int x = 3 + ((n / 15) * 3);
    if (n <= 2)
        cout << n + 1 << endl;
    else if ((n % 3) == (n % 5))
    {
        int count = 0;
        while (n % 3 == n % 5)
        {
            n--;
            count++;
        }
        cout << (3 + (n / 15) * 3) + count << endl;
    }
    else
        cout << x << endl;
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
    // for (int i = 0; i <= 100; i++)
    //     cout << i << " " << i % 3 << " " << i % 5 << " " << ((i % 3) == (i % 5)) << endl;
    // cout << endl;
    return 0;
}