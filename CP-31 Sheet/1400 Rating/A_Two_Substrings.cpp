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
    bool f1 = 0, f2 = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (f1 == 0 && s[i] == 'A' && s[i + 1] == 'B')
        {
            f1 = true, i++;
        }
        else if (f1 && s[i] == 'B' && s[i + 1] == 'A')
        {
            yes;
            return;
        }
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (f2 == 0 && s[i] == 'B' && s[i + 1] == 'A')
        {
            f2 = true, i++;
        }
        else if (f2 && s[i] == 'A' && s[i + 1] == 'B')
        {
            yes;
            return;
        }
    }
    no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}