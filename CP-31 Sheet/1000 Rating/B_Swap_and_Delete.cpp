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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c : s)
        if (c == '0')
            a++;
        else
            b++;
    for (auto c : s)
    {
        if (c == '0')
            b--;
        else
            a--;
        if (a < 0 || b < 0)
        {
            cout << a + b + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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