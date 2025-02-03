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
int p[N], pf[N];
void marwan()
{
    int n;
    cin >> n;
    memset(p, 0, sizeof(p));
    memset(pf, 0, sizeof(pf));
    vector<pair<int, int>> v(n);
    int start
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        p[x - 1]++, p[y]--;
    }
    for(int i = )
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}