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
    int n, k;
    cin >> n >> k;
    vector<string> v(k);
    for (int i = 0; i < k; i++)
        cin >> v[i];

    int low = 1, high = n, ans;
    string f;
    auto ok = [&](int m)
    {
        int last = 0;
        for (int i = 0; i < n; i++)
        {

        }
    };
    while (low <= high)
    {
        int m = low + (high - low) / 2;
        if (ok(m))
        {
            ans = m, high = m - 1;
        }
        else
            low = m + 1;
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