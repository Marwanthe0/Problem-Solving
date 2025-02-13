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
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        yes;
        cout << a << endl;
        return;
    }
    if (a.back() == b.back())
    {
        yes;
        cout << "*" << a.back() << endl;
        return;
    }
    else if (a.front() == b.front())
    {
        yes;
        cout << a.front() << "*" << endl;
        return;
    }
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < b.size() - 1; j++)
        {
            if (a[i] == b[j] && a[i + 1] == b[j + 1])
            {
                yes;
                cout << "*" << a[i] << a[i + 1] << "*" << endl;
                return;
            }
        }
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