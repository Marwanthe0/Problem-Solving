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
    vector<int> v(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    v[0] = v[1] - 1, v.back() = v[n] + (v[n] - v[n - 1] + 1);
    vector<int> fr(n + 2, 0), bc(n + 2, 0);
    fr[0] = 1, bc.back() = 1;
    int last = v[0], lastd = 0;
    for (int i = 1; i <= n; i++)
    {
        int dif = v[i] - last;
        bool f1 = false, f2 = false;
        if (dif > 0 || i < 2)
            f1 = true;
        if (i > 2)
        {
            int dif2 = dif - lastd;
            if (dif2 > 0)
                f2 = true;
        }
        else
            f2 = true;
        if (f1 && f2 && fr[i - 1])
            fr[i] = 1;
        last = v[i];
        lastd = dif;
    }
    last = v.back(), lastd = INT_MAX;
    for (int i = n; i >= 1; i--)
    {
        int dif = last - v[i];
        bool f1 = false, f2 = false;
        if (dif > 0 || i == n)
            f1 = true;
        if (i < n - 1)
        {
            int dif2 = lastd - dif;
            if (dif2 > 0)
            {
                f2 = true;
            }
        }
        else
            f2 = true;
        if (f1 && f2 && bc[i + 1])
            bc[i] = 1;
        last = v[i];
        lastd = dif;
    }

    // for (int i = 0; i <= n + 1; i++)
    //     cout << fr[i] << " ";
    // cout << endl;
    // for (int i = 0; i <= n + 1; i++)
    //     cout
    //         << bc[i]
    //         << " ";
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            if (bc[i + 1])
                cout << 1;
            else
                cout << 0;
        }
        else if (i == n)
        {
            if (fr[i - 1])
                cout << 1;
            else
                cout << 0;
        }
        else
        {
            if (fr[i - 1] && bc[i + 1] && (v[i + 1] > v[i - 1] && (v[i + 1] - v[i - 1] > v[i - 1] - v[i - 2])))
                cout << 1;
            else
                cout << 0;
        }
    }
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