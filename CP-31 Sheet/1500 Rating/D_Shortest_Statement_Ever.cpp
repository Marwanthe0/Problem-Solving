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
void printbn(int x)
{
    for (int i = x; i >= 0; i--)
    {
        cout << ((x >> i) & 1);
    }
    cout << endl;
}

int f(int i, int a, int b, int oa, map<pair<int, int>, int> &dp)
{
    if (i < 0)
    {
        return abs(a - oa);
    }
    if (dp.find({i, a}) != dp.end())
        return dp[{i, a}];
    int x = (1 & (b >> i)), y = (1 & (a >> i));
    if (x == 0 && y == 0)
    {
        int first = f(i - 1, a, b, oa, dp);
        int tmp = a;
        a |= (1ll << i);
        int second = f(i - 1, a, b, oa, dp);
        a = tmp;
        return dp[{i, a}] = min(first, second);
    }
    else if (x == 1 && y == 1)
    {
        int tmp = a;
        a &= (~(1ll << i));
        return dp[{i, a}] = f(i - 1, a, b, oa, dp);
    }
    else
    {
        return dp[{i, a}] = f(i - 1, a, b, oa, dp);
    }
}
void marwan()
{
    int a, b;
    cin >> a >> b;
    for (int i = max(__lg(a), __lg(b)); i >= 0; i--)
    {
        cout << ((a >> i) & 1);
    }
    cout << endl;
    for (int i = max(__lg(a), __lg(b)); i >= 0; i--)
    {
        cout << ((b >> i) & 1);
    }
    cout << endl;
    cout << endl;
    map<pair<int, int>, int> dp;
    int x = f(32, a, b, a, dp);
    cout << x << endl;
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