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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0, z = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 's')
            x++;
        else if (s[i] == 'p')
            y++;
        else
            z++;
    }
    if (x == 0 || y == 0)
    {
        yes;
        return;
    }
    if (s[0] == 's')
    {
        for (int i = 1; i < n; i++)
        {
            if (s[i] != 's')
                count++;
        }
        if (count == n - 1)
        {
            yes;
            return;
        }
    }
    if (s[n - 1] == 'p')
    {
        count = 0;
        for (int i = 0; i < n - 1; i++)
            if (s[i] != 'p')
                count++;
        if (count == n - 1)
        {
            yes;
            return;
        }
    }
    no;
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