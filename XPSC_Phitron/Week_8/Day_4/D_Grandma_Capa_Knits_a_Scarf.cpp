#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        int c = i + 'a', l = 0, r = n - 1, count = 0;
        while (l < r)
        {
            if (s[l] == s[r])
                l++, r--;
            else if (s[l] == c)
                l++, count++;
            else if (s[r] == c)
                r--, count++;
            else
                break;
        }
        if (l >= r)
        {
            ans = min(ans, count);
        }
    }
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
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