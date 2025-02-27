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
    int n, o, p;
    cin >> n >> o >> p;
    string s;
    cin >> s;
    vector<pair<int, int>> v(o);
    vector<int> pf;
    pf.push_back(0);
    pf.push_back(n - 1);
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        x--, y--;
        for (int i = x; i <= y; i++)
        {
            s.push_back(s[i]);
        }
        pf.push_back(pf.back() + (y - x + 1));
    }
    cerr << s << endl;
    for (int i = 0; i < p; i++)
    {
        int k;
        cin >> k;
        k--;
        cout << s[k] << endl;
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