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
    vector<int> v(n);
    set<int> a = {2, 4, 8}, b = {6};
    for (auto &vl : v)
        cin >> vl;
    if (all_of(all(v), [&](int x)
               { return x == v[0]; }))
    {

        yes;
        return;
    }
    else if (all_of(all(v), [&](int x)
                    { return (x % 5) == 0; }))
    {
        for (auto &vl : v)
            if (vl % 10 == 5)
                vl += 5;
        if (all_of(all(v), [&](int x)
                   { return x == v[0]; }))
        {
            yes;
        }
        else
            no;
        return;
    }
    else if (any_of(all(v), [&](int x)
                    { return (x % 5) == 0; }))
    {
        no;
        return;
    }
    for (auto &vl : v)
    {
        if ((vl % 10) & 1)
            vl += (vl % 10);
    }
    int x = ((v[0] / 10) % 10);
    bool t = (a.find((v[0] % 10)) != a.end());
    bool flag = true, flag2 = true;
    for (int i = 0; i < n; i++)
    {
        int y = ((v[i] / 10) % 10);
        bool tt = (a.find(v[i] % 10) != a.end());
        if ((x & 1) == (y & 1))
        {
            if (t != tt)
            {
                flag = false;
                break;
            }
        }
        else
        {
            if (t == tt)
            {
                flag = false;
            }
        }
    }
    if (flag)
        yes;
    else
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