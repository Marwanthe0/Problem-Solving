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
    int n = s.size();
    int count = 0;
    bool flag = false;
    if (n == 1)
    {
        if (s[0] == '0')
            cout << 1 << endl;
        else
        {
            cout << "INVALID" << endl;
        }
        return;
    }
    for (int i = 0; i < n - 1;)
    {
        if (s[i] == '\\' && s[i + 1] == '\\')
            i++, count++;
        else if (s[i] == '\\' && s[i + 1] == '0')
            break;
        else if (s[i] == '0')
            count++;
        i++;
        if (i == n - 1)
            flag = true;
    }
    if (flag)
    {
        if (s[n - 1] == '\\')
        {
            cout << "INVALID" << endl;
            return;
        }
        else
            count++;
    }
    cout << count << endl;
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