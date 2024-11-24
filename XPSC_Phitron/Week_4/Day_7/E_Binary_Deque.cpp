#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = 0, sum = 0, ans = INT_MIN;
    ll acc = accumulate(v.begin(), v.end(), 0); if (acc < k)
    {
        cout << -1 << endl;
        return;
    }
    while (l < n && r < n)
    {
        sum += v[r];
        if (sum == k)
        {
            ans = max(ans, r - l + 1);
        }
        else if (sum > k)
        {
            while (sum > k && l < r)
            {
                sum -= v[l++];
            }
            if (sum == k)
            {
                ans = max(ans, r - l + 1);
            }
        }
        r++;
    }
    cout << n - ans << endl;
}
int main()
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