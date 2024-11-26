#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1];
        pf[i] = pf[i - 1] + v[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            if (pf[i + 1] == (pf.back() - pf[i + 1]))
                ans += 2;
            else if (abs((pf.back() - pf[i + 1]) - pf[i + 1]) == 1)
                ans++;
        }
    }
    cout << ans << endl;
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