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
int val(string s)
{
    int count = 0, bit = 0;
    for (auto c : s)
    {
        if ((c - '0') == bit)
            count++;
        else
            bit = 1 - bit, count += 2;
    }
    return count;
}
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = val(s);
    // s = '0' + s;
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag == false && (s[i] != s[i + 1]))
        {
            flag = true;
            i++;
        }
        else if (flag && (s[i] != s[i + 1]))
        {
            cout << ans - 2 << endl;
            return;
        }
    }
    // 0110 = 1212 = 6
    // 0011 = 1121 = 5
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
        {
            cout << ans - 1 << endl;
            return;
        }
    }
    cout << ans << endl;
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