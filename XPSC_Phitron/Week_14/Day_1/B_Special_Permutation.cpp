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
    int n, a, b;
    cin >> n >> a >> b;
    if ((a <= n / 2 && b <= n / 2) || (a > n / 2 && b > n / 2) || (b < n / 2) || (n - a + 1 < n / 2))
    {
        cout << -1 << endl;
        return;
    }
    int count = 0;
    vector<int> v(n + 1, 0);
    cout << a << " ";
    v[a]++;
    for (int i = n; count < (n / 2) - 1; i--)
    {
        if (i == b)
            continue;
        cout << i << " ";
        v[i]++;
        count++;
    }
    for (int i = 1; i <= n; i++)
        if (!v[i])
            cout << i << " ";
    cout << endl;
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