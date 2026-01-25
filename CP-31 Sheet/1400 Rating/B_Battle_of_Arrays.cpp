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
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }

    int count = 0;
    while (a.size() && b.size())
    {
        int x = *(--a.end()), y = *(--b.end());
        if (count & 1)
        {
            a.erase(--a.end());
            if (x >= y)
            {
                a.insert(x - y);
            }
        }
        else
        {
            b.erase(--b.end());
            if (x <= y)
            {
                b.insert(y - x);
            }
        }
        count++;
    }
    if (count & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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