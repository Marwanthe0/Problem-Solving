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
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[(-1 * x)]++;
        s.insert((-1 * x));
    }
    // for (auto vl : ms)
    // {
    //     cout << vl << " ";
    // }
    int first = *s.begin(), count = 1;
    m[first]--;
    if (m[first] <= 0)
        m.erase(m.find(first)), s.erase(first);
    int rem = ((-1) * k) - (first);
    int i = 0;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (rem > *(--s.end()))
        {
            rem = (-1 * k), flag = true;
        }
        auto it = s.lower_bound(rem);
        if (flag)
            count++, flag = false;
        rem -= *it;
        if (rem >= 0)
            rem = ((-1) * k), flag = true;
        m[*it]--;
        if (m[*it] <= 0)
            s.erase(it), m.erase(*it);
    }
    cout << count << endl;
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