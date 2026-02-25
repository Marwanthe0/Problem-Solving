#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    string s;
    cin >> s;
    sort(s.begin() + 1, s.end());
    int count = (s[0] - '0'), ans = 0, sum = 0, idx = (int)s.size() - 1, sum2 = 0;
    for (int i = 0; i < s.size(); i++)
        sum += (s[i] - '0');
    sum2 = sum;
    while (idx > 0 && sum >= 10)
    {
        sum -= (s[idx] - '0');
        ans++, idx--;
    }
    int ans2 = 1;
    idx = s.size() - 1;
    sum2 -= ((s[0] - '0') - 1);
    while (idx > 0 && sum2 >= 10)
    {
        sum2 -= (s[idx] - '0');
        ans2++, idx--;
    }
    cout << min(ans, ans2) << endl;
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