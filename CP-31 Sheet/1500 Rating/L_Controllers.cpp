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
    int x = 0ll, y = 0ll;
    for (auto c : s)
    {
        if (c == '+')
            x++;
        else
            y++;
    }
    if (x > y)
        swap(x, y);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (x == 0 || y == 0)
        {
            no;
            continue;
        }
        if (a == b)
        {
            if (x == y)
            {
                yes;
                continue;
            }
            else
            {
                no;
                continue;
            }
        }
        if (a > b)
            swap(a, b);
        if ((a * 1ll * y == b * 1ll * x) || (x == y))
        {
            yes;
        }
        else
        {
            if (a == b)
            {
                no;
                continue;
            }
            int tn = (int)(((a * 1ll * y) - (b * 1ll * x))) / ((a - b));
            if ((int)(((a * 1ll * y) - (b * 1ll * x))) % ((a - b)))
            {
                no;
                continue;
            }
            if (tn >= 0ll && tn < x && ((x - tn) * 1ll * b) == ((y - tn) * 1ll * a))
            {
                yes;
            }
            else
                no;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}