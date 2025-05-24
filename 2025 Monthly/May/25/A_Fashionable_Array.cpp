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
    multiset<int> ms, tmp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    tmp = ms;
    int c1 = 0, c2 = 0;
    // cerr << *ms.begin() << " " << *(--ms.end()) << endl;
    while (*ms.begin() + *(--ms.end()) & 1)
    {
        ms.erase(ms.begin());
        c1++;
    }
    ms = tmp;
    while (*ms.begin() + *(--ms.end()) & 1)
    {
        ms.erase(--ms.end());
        c2++;
    }
    cout << min(c1, c2) << endl;
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