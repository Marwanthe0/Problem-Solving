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
    vector<int> v;
    for (int i = 0; i < (1 << n); i++)
        v.push_back(i);
    sort(all(v), [&](int a, int b)
         {if(__builtin_ctz(~a) == __builtin_ctz(~b)) return a < b; else return __builtin_ctz(~a) > __builtin_ctz(~b); });
    for (auto vl : v)
        cout << vl << " ";
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