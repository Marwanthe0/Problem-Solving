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
    string s, t;
    cin >> s >> t;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && t[i] == '1')
        {
            no;
            return;
        }
        else if (s[i] == '1' && t[i] == '0')
        {
            count++;
        }
    }
    if (count & 1)
        no;
    else
        yes;
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