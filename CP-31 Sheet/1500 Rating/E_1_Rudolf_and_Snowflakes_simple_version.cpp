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
vector<int> v(1e6 + 10, 0);
void marwan()
{
    int n;
    cin >> n;
    if (v[n])
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 2; i <= 1e5; i++)
    {
        int y = 1 + i;
        // cerr << y << endl;
        for (int j = i * i; y + j <= 1e6; j *= i)
        {
            y += j;
            v[y] = 1;
            // cerr << y << " ";
        }
        // cerr << endl;
    }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}