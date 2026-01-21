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
    string s;
    cin >> s;
    int x = 0, y = 0, op = 0, cl = 0;
    for (auto c : s)
        if (c == ')')
            cl++;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '(')
            x++;
        else
            y++, cl--;
        if (s[i] == '(' && y && (x - y + 1) <= cl)
        {
            cout << n - 2 << endl;
            return;
        }
    }
    cout << -1 << endl;
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