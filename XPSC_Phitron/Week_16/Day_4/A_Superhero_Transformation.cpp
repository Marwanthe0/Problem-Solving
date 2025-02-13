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
map<char, int> m = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
void marwan()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), nn = t.size();
    if (n != nn)
    {
        no;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[s[i]] != m[t[i]])
        {
            no;
            return;
        }
    }
    yes;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}