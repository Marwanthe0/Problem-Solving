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
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    if ((n == 2 && s[0] != s[1]) || (n % 2))
    {
        no;
        return;
    }
    int hor = m['N'] + m['S'], ver = m['W'] + m['E'];
    if (ver & 1 || hor & 1)
    {
        no;
        return;
    }
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'N' || s[i] == 'S')
        {
            if (m[s[i]] % 2)
            {
                ans.push_back('H');
            }
            else
                ans.push_back('R');
            m[s[i]]--;
        }
        else
        {
            if (m[s[i]] % 2)
            {
                ans.push_back('R');
            }
            else
                ans.push_back('H');
            m[s[i]]--;
        }
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