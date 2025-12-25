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
    string a, b;
    cin >> a >> b;
    vector<pair<int, int>> v(n);
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '0')
            x++;
        else
            y++;
        v[i].first = x, v[i].second = y;
        // cerr << x << " " << y << endl;
    }
    bool flag = (a.back() == b.back());
    if (n == 1 && (a.back() != b.back()))
    {
        no;
        return;
    }
    for (int j = n - 1; j >= 0; j--)
    {
        cerr << v[j].first << " " << v[j].second << " " << a[j] << " " << b[j] << ":" << flag << endl;
        if (((a[j] == b[j]) != flag) || (j == n - 1 && (a[j] != b[j])))
        {
            if ((v[j].first == v[j].second))
            {
                if (j != n - 1)
                {
                    if (flag)
                        flag = false;
                    else
                        flag = true;
                }
            }
            else
            {
                no;
                return;
            }
        }
    }
    yes;
    cerr << endl;
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