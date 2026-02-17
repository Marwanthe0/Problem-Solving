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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.front() == s.back())
    {
        if (s.front() == 'A')
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
        return;
    }
    else if (s.front() == 'A')
    {
        for (int i = 1; i < n - 1; i++)
            if (s[i] == 'B')
            {
                cout << "Bob" << endl;
                return;
            }
        cout << "Alice" << endl;
    }
    else
    {

        if (n == 2 || s[n - 2] == 'B')
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
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