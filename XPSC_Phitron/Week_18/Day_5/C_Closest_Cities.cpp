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
    vector<int> v = {INT_MIN}, cl = {0}, tl = {0};
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v.push_back(INT_MAX);
    for (int i = 1; i < n; i++)
    {
        int d1 = v[i] - v[i - 1], d2 = v[i + 1] - v[i];
        if (d2 < d1)
        {
            cl.push_back(cl.back() + 1);
        }
        else
        {
            cl.push_back(cl.back() + max(d1, d2));
        }
    }
    for (int i = n; i > 1; i--)
    {
        int left = v[i] - v[i - 1], right = v[i + 1] - v[i];
        if (left < right)
        {
            tl.push_back(tl.back() + 1);
        }
        else
        {
            tl.push_back(tl.back() + left);
        }
    }
    reverse(all(tl));

    // for (auto vl : cl)
    //     cout << vl << " ";
    // cout << endl;

    // for (auto vl : tl)
    //     cout << vl << " ";
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (y > x)
            cout << cl[y - 1] - cl[x - 1] << endl;
        else
        {
            cout << (-1) * (tl[x - 1] - tl[y - 1]) << endl;
        }
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