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
    int n = a.size();
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            s.insert(i);
    }
    vector<pair<int, int>> temp;
    int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '0')
            {
                if (l1 == -1)
                {
                    l1 = i;
                }
                else
                {
                    r1 = i;
                }
            }
            if (a[i] == '1')
            {
                if (l2 == -1)
                {
                    l2 = i;
                }
                else
                {
                    r2 = i;
                }
            }
        }
    }
    cerr << l1 << " " << r1 << "   " << l2 << " " << r2 << endl;
    for (auto vl : s)
    {
        if ((vl >= l1 && vl <= r1) || (vl >= l2 && vl <= r2))
            continue;
        else
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
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}