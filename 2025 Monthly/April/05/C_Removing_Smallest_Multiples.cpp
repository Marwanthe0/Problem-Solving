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
    s = '1' + s;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // if (s[i] == '1')
        //     continue;
        int k = 1, j = i;
        while (k * i <= n)
        {
            j = i * k, k++;
            if (s[j] == '0')
            {
                ans += i, s[j] = '1';
            }
            else
                break;
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