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
    multiset<int, greater<int>> ms;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ms.insert(v[a - 1]);
        ms.insert(v[b - 1]);
    }
    for (auto vl : v)
        ms.erase(ms.find(vl));
    int sum = accumulate(all(v), 0ll);
    cout << sum << " ";
    for (int i = 1; i < n - 1; i++)
    {
        sum += *ms.begin();
        ms.erase(ms.begin());
        cout << sum << " ";
    }
    cout << endl;
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