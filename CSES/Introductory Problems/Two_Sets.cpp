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
    if (((n * (n + 1)) / 2) & 1)
    {
        no;
        return;
    }
    yes;
    int sum = (n * (n + 1)) / 4, x = n;
    set<int> ans;
    while (x >= 0)
    {
        if (sum >= x)
            ans.insert(x), sum -= x;
        if (sum == 0)
            break;
        x--;
    }
    cout << ans.size() << endl;
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
    cout << n - ans.size() << endl;
    for (int i = 1; i <= n; i++)
        if (!ans.count(i))
            cout << i << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}