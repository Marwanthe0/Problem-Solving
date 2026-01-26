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
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    multiset<int> ms2 = ms;
    bool flag = false;
    while (!ms.empty())
    {
        if (ms.size() == 1)
        {
            break;
        }
        auto it = (--ms.end());
        int x = *it, y = *(--it);
        ms.erase(--ms.end());
        ms.erase(it);
        if (y != x)
            ms.insert(x - y);
    }
    if (ms.empty())
        flag = true;
    ms = ms2;
    while (!ms.empty())
    {
        if (ms.size() == 1)
        {
            break;
        }
        auto it = (ms.begin());
        int x = *it, y = *(++it);
        ms.erase(ms.begin());
        ms.erase(it);
        if (y != x)
            ms.insert(y - x);
    }
    if (ms.empty())
        flag = true;
    ms = ms2;
    while (!ms.empty())
    {
        if (ms.size() == 1)
        {
            break;
        }
        int x = *ms.begin(), y = *(--ms.end());
        ms.erase(ms.begin());
        ms.erase(--ms.end());
        if (y != x)
            ms.insert(y - x);
    }
    if (ms.empty())
        flag = true;
    if (flag)
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}