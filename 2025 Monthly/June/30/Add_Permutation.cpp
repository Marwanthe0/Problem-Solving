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
    int n, m;
    if (m >= (n / 2 + (n % 2 != 0)))
    {
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
        {
            v[i - 1] = i;
        }
        m = n - m;
        for (int i = 0; i < m; i++)
        {
            swap(v[2 * i], v[2 * i + 1]);
        }
    }
    else
    {
        vector<int> v(n);
        for (int i = n; i >= 1; i--)
        {
            v[i - 1] = i;
        }
        if (m & 1)
        {
            m /= 2;
            for (int i = 0; i < m; i++)
            {
                swap(v[2 * i], v[2 * i + 1]);
            }
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                swap(v[2 * i], v[2 * i + 1]);
            }
        }
    }
    for (auto vl : v)
        cout << vl << " ";
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