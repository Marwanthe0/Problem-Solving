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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = n - 1, ans = accumulate(all(v), 0ll), lrem = 0, rrem = 0;
    while (l <= r)
    {
        int val = l + r + 2;
        int sum = val * (r - l + 1);
        ans = max(ans, sum + lrem + rrem);
        int lsum = ((val + 1) * (r - l)) + v[l] + lrem, rsum = ((r - l) * (val - 1) + v[r]) + rrem;
        if (lsum > rsum)
        {
            lrem += v[l];
            ans = max(ans, lsum);
            l++;
        }
        else
        {
            rrem += v[r];
            ans = max(ans, rsum);
            r--;
        }
    }
    cout << ans << endl;

    /*
    val = 0 + 2 + 2 = 4
    sum = 4*3 = 12
    ans = 12
    lsum = 5*2 + 2 = 12,rsum = 2*3 + 1 = 7
    lsum > rsum:
        l++

    l = 1,r = 2
    val = 5
    sum = 5*2 = 10
    ans =
    */
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