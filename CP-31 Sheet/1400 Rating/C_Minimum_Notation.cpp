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
    int n = s.size();
    int mn = 9;
    deque<char> d;
    multiset<char> ms;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] - '0') > mn)
        {

            ms.insert('0' + (min(9, (s[i] - '0') + 1)));
        }
        else
            ms.insert(s[i]);
        mn = min(mn, (int)(s[i] - '0'));
    }
    for (auto vl : ms)
        cout << vl;
    cout << endl;
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