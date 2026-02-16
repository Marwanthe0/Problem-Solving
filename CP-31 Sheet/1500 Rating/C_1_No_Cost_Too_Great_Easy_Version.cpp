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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
bool first(vector<int> &v)
{
    int n = v.size();
    map<int, int> m;
    int count = 1;
    for (auto vl : v)
    {
        int x = vl;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (m.count(i) && m[i] != count)
                {
                    return true;
                }
                m[i] = count;
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x > 1 && m.count(x) && m[x] != count)
            return true;
        if (x > 1)
            m[x] = count;
        count++;
    }
    return false;
}
bool second(vector<int> &v)
{
    int n = v.size();
    map<int, int> m, p;
    int count = 1;
    for (auto vl : v)
    {
        int y = vl + 1;
        for (int i = 2; i * i <= y; i++)
        {
            if (y % i == 0)
            {
                if (m.count(i))
                    return true;
                p[i] = count;
                while (y % i == 0)
                {
                    y /= i;
                }
            }
        }
        if (y > 1)
            p[y] = count;
        if (y > 1 && m.count(y))
            return true;
        int x = vl;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (p.count(i) && p[i] != count)
                    return true;
                m[i] = count;
                while (x % i == 0)
                {
                    x /= i;
                }
            }
        }
        if (x > 1 && p.count(x) && p[x] != count)
            return true;
        if (x > 1)
            m[x] = count;
        count++;
    }
    return false;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    sort(all(a));
    if (first(a))
    {
        cout << 0 << endl;
        return;
    }
    else if (second(a))
    {
        cout << 1 << endl;
        return;
    }
    else
        cout << 2 << endl;
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