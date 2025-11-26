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
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    int count = 0;
    char t;
    for (auto [x, y] : m)
    {
        if (y & 1)
            count++, t = x;
        if (count > 1)
        {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    string ans;
    for (auto [x, y] : m)
    {
        int tt = y / 2;
        while (tt--)
            ans += x;
    }
    string k = ans;
    reverse(all(ans));
    cout << k;
    if (count)
        cout << t;
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}