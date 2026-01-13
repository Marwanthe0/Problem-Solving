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
    int ans = 0, x = 0, y = 0, count = 0, cnt = 0, a = 0, b = 0;
    for (auto &vl : v)
    {
        cin >> vl;
        if (vl > 0)
        {
            count++;
            ans += count;
        }
        else
        {
            if (cnt & 1)
            {
                b += (count + 1);
            }
            else
                a += (count + 1);
            count = 0, cnt++;
        }
        if (cnt & 1)
            ans += b;
        else
            ans += a;
    }
    cout << (n * (n + 1) / 2) - ans << " " << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}