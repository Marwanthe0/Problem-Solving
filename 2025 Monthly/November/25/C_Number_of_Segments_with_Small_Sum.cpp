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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    // for (auto vl : v)
    //     cout << vl << " ";
    int l = 0, r = 0, ans = 0, sum = 0;
    while (r < n)
    {
        sum += v[r];
        while (sum > k)
            sum -= v[l], l++;
        if (sum <= k)
            ans += (r - l + 1);
        r++;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}