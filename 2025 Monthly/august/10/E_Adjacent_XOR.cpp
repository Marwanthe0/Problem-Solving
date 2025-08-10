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
    vector<int> b(n);
    vector<pair<int, int>> a(n);
    for (auto &vl : a)
    {
        int tmp;
        cin >> tmp;
        vl.first = tmp, vl.second = -1;
    }
    for (auto &vl : b)
        cin >> vl;
    // for (auto [x, y] : a)
    //     cerr << x << " " << y << endl;
    // cerr << endl;
    if (a[n - 1].first != b[n - 1])
    {
        no;
        return;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i].first == b[i])
            continue;
        if (a[i].second == -1)
        {
            cerr << "c1";
            if ((a[i].first ^ a[i + 1].first) == b[i])
            {
                cerr << "c2" << b[i];
                a[i].second = b[i];
                a[i].first = b[i];
            }
            else if ((a[i + 1].second != -1 && a[i].first ^ a[i + 1].second == b[i]))
            {
                a[i].first = b[i];
                a[i].second = b[i];
            }
            else
            {
                no;
                return;
            }
        }
        else
        {
            if (a[i].first ^ a[i + 1].first == b[i])
            {
                a[i].first = b[i];
                a[i].second = b[i];
            }
            else if (a[i].second != -1)
            {
                if (a[i].second ^ a[i + 1].first == b[i])
                {
                    a[i].first = b[i];
                    a[i].second = b[i];
                }
                else if (a[i + 1].second != -1)
                {
                    if (a[i].second ^ a[i + 1].second == b[i])
                    {
                        a[i].first = b[i];
                        a[i].second = b[i];
                    }
                }
            }
            else if (a[i + 1].second != -1 && a[i].first ^ a[i].second == b[i])
            {
                a[i].first = b[i];
                a[i].second = b[i];
            }
            else
            {
                no;
                return;
            }
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