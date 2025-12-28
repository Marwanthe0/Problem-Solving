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
char nxt(char c)
{
    if (c == 'z')
        return 'a';
    else
        return ++c;
}
char nt(char a, char b)
{
    if (nxt(a) == b)
        return nxt(b);
    else
        return nxt(a);
}
void marwan()
{
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            if (i == n - 1)
            {
                s[i] = nxt(s[i]);
            }
            else
            {
                s[i] = nt(s[i - 1], s[i + 1]);
            }
        }
    }
    cout << s << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}