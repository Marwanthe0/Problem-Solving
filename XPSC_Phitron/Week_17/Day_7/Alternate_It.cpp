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
    int n = s.size(), flag = 1;
    int a = 0, b = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << 0 << endl;
        return;
    }
    for (auto c : s)
        if (c == '1')
            a++;
        else
            b++;
    if (abs(a - b) < 2)
    {
        cout << 1 << endl;
    }
    else if (abs(a - b) == 2 || abs(a - b) == 3)
    {
        cout << 2 << endl;
    }
    else
        cout << 3 << endl;
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