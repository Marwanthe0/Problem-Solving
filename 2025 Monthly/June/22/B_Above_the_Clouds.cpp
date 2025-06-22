#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> a = {s[0]}, b = {s[n - 1]};
    for (int i = 1; i < n - 1; i++)
    {
        if (a.find(s[i]) != a.end())
        {
            yes;
            return;
        }
        a.insert(s[i]);
    }
    for (int i = n - 2; i > 0; i--)
    {
        if (b.find(s[i]) != b.end())
        {
            yes;
            return;
        }
        b.insert(s[i]);
    }
    no;
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