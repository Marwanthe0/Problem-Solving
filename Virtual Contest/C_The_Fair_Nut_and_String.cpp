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
int ans(string s, int i, int cnt)
{
    if (i == s.size())
        return 1;
    int nt = ans(s, i + 1, cnt), n = 0;
    if (s[i] == cnt + 'a')
        n += ans(s, i + 1, cnt + 1);
    return nt + n;
}
void marwan()
{
    string s;
    cin >> s;
    cout << ans(s, 0, 0) - 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}