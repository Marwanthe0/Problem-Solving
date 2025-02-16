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
    int count = 0;
    string t;
    for (int i = 0; i < n; i++)
    {
        if (!t.empty())
        {
            if (s[i] != t.back())
                t.push_back(s[i]);
        }
        else
            t.push_back(s[i]);
    }
    int k = t.size();
    if (*s.begin() == '0')
        k--;
    cout << k << endl;
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