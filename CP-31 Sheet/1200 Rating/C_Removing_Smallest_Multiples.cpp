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
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    vector<bool> flag(n + 10);
    for (int i = 1; i <= n; i++)
        flag[i] = true;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = i; j <= n; j += i)
        {
            if (s[j] == '0')
            {
                if (flag[j])
                {
                    flag[j] = false;
                    count++;
                }
            }
            else
                break;
        }
        ans += i * count;
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