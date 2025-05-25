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
    int a, b, r;
    cin >> a >> b >> r;
    int q;
    cin >> q;
    while (q--)
    {
        int c, d;
        cin >> c >> d;
        int dis = (pow(abs(c - a), 2)) + pow(abs(d - b), 2);
        if (r * r == dis)
            cout << "On" << endl;
        else if (dis < r * r)
            cout << "Inside" << endl;
        else
            cout << "Outside" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}