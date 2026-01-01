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
    k++;
    vector<int> v(n), con(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i < n; i++)
    {
        if ((v[i - 1]) < (v[i] * 2))
        {
            con[i] = 1;
        }
        else
            con[i] = 0;
    }
    con[0] = 1;
    // for (int i = 0; i < (n / 2); i++)
    // {
    //     int x = i + 1;
    //     con[i] = con[(n - 1) - i] = min(x, k);
    // }
    // if (n & 1)
    //     con[n / 2] = k;
    // for (int i = 0; i < n; i++)
    // {
    //     cerr << con[i] << " ";
    // }
    // cerr << endl;
    int l = 0, r = 0, sm = 1, ans = 0;
    while (r < n)
    {
        if (con[r] == 0)
        {
            int past = r;
            for (int i = past + 1; i < min(past + k, n); i++)
            {
                if (con[i] == 0)
                    past = i;
            }
            l = past, r = past + k - 1;
            sm = 1;
        }
        if (r >= n)
            break;
        if (r - l + 1 == k)
        {
            ans++;
            l++;
        }
        r++;
    }
    cout << ans << endl;
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