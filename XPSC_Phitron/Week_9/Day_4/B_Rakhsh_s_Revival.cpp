#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int count = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count++;
            if (count == m)
            {
                ans++;
                i += (k - 1);
                count = 0;
            }
        }
        else
            count = 0;
    }
    cout << ans << endl;
}
int main()
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