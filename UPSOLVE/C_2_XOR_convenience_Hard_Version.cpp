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
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v.back() = 1;
    map<int, int> m;
    for (int i = 2; i < n; i++)
    {
        v[i] = i ^ 1;
        m[v[i]] = i;
    }
    m[1] = n;
    for (int i = 1; i <= n; i++)
    {
        cerr << v[i] << " ";
    }
    cerr << endl;
    int x = n - (n & 1);
    int cpos = 1;
    if (m.find(cpos ^ x) != m.end())
    {
        v[1] = x;
    }
    if (!v[1])
    {
        for (int i = 2; i < n; i++)
        {
            if (m.find(1 ^ v[i]) != m.end() && m[i ^ x] > i)
            {
                v[1] = x;
                swap(v[1], v[i]);
                break;
            }
        }
    }
    if (!v[1])
        cout << -1 << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
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