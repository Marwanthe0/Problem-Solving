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
vector<int> divisors(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                v.push_back(n / i);
            v.push_back(i);
        }
    }
    sort(all(v));
    return v;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans = divisors(n);
    if (k > ans.size())
        cout << -1 << endl;
    else
        cout << ans[k - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}