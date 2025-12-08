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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c : s)
    {
        if (c == '1')
            a++;
        else
            b++;
    }
    int mx = max(a, b), mn = min(a, b);
    a = mx, b = mn;
    // cerr << a << " " << b << endl;
    for (int j = 0; j < k; j++)
    {
        int count = ((a > b) ? 0 : 1);
        for (int i = j; i < n; i += k)
        {
            if (count & 1)
                b--;
            else
                a--;
            if (a < 0 || b < 0)
            {
                // cerr << i << " " << j << endl;
                no;
                return;
            }
            count++;
        }
    }
    yes;
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