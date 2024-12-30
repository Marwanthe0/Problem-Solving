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
    string ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == '0')
    //     {
    //         ans.push_back('0');
    //         while (i < n && s[i] != '1')
    //             i++;
    //         i--;
    //     }
    //     else
    //     {
    //         ans.push_back('1');
    //         while (i < n && s[i] != '0')
    //             i++;
    //         i--;
    //     }
    // }
    int x = 0, y = 0;
    for (auto vl : s)
    {
        if (vl == '0')
            x++;
        else
            y++;
    }
    if (y >= x)
        yes;
    else
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