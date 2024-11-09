#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, ans = 0;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x)
        {
            ms.insert(x);
        }
        else if (!ms.empty())
        {
            ans += *ms.rbegin();
            ms.erase(--ms.end());
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