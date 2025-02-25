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
    int n, k;
    cin >> n >> k;
    int xx = 0;
    for (int i = 0; i < n; i++)
    {
        xx |= i;
    }
    if (xx == k)
    {
        for (int i = 0; i < n; i++)
            cout << i << " ";
        cout << endl;
        return;
    }
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if ((k | i) == k)
            v.push_back(i);
        else
            break;
    }
    if (v.size() == n)
    {
        v.pop_back();
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < v.size())
        {
            cout << v[i] << " ";
            x |= v[i];
        }
        else
        {
            cout << k << " ";
            x |= k;
        }
    }
    cout << endl;
    cerr << (x == k) << endl;
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