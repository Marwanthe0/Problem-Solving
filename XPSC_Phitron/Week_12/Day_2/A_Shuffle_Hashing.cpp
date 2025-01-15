#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s, t;
    cin >> s >> t;
    if (t.size() < s.size())
    {
        no;
        return;
    }
    map<int, int> m, x;
    for (auto c : s)
        m[c]++;
    int l = 0, r = 0;
    while (r < t.size())
    {
        x[t[r]]++;
        if (m == x)
        {
            yes;
            return;
        }
        if (r - l + 1 == s.size())
        {
            x[t[l]]--;
            if (x[t[l]] <= 0)
                x.erase(t[l]);
            l++;
        }
        if (m == x)
        {
            yes;
            return;
        }
        r++;
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