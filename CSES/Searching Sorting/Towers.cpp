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
    multiset<int> ms;
    ms.insert(v.front());
    for (int i = 1; i < n; i++)
    {
        auto it = ms.upper_bound(v[i]);
        if (it == ms.end())
            ms.insert(v[i]);
        else
        {
            ms.erase(it);
            ms.insert(v[i]);
        }
    }
    cout << ms.size() << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}