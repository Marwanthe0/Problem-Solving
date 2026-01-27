#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 10000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
pair<int, int> pw(int a, int b)
{
    if (b == 1)
        return {0, (int)a};
    if (b & 1)
    {
        pair<int, int> x = pw(a, b - 1);
        if ((a * 1ll * x.second) >= M)
        {
            return {x.first + 1, ((a % M) * 1ll * (x.second % M)) % M};
        }
        return {x.first, 1 * 1ll * x.second};
    }
    pair<int, int> x = pw(a, b / 2);
    if (x.second * 1ll * x.second >= M)
        return {x.first + 1, ((x.second % M) * 1ll * (x.second % M)) % M};

    return {x.first, (x.second * 1ll * x.second)};
}
void marwan()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, int> x = pw(a, b), y = pw(c, d);
    cerr << x.first << " " << x.second << endl;
    cerr << y.first << " " << y.second << endl;
    if (x.first > y.first)
        yes;
    else if (x.first == y.first && x.second > y.second)
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}