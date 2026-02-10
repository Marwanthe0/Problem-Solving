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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), aa, bb;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            count++;
        }
        else
        {
            if (count >= k)
                aa.push_back(count);
            count = 0;
        }
    }
    count = 0;
    for (int i = 0; i < m; i++)
    {
        if (b[i])
        {
            count++;
        }
        else
        {
            if (count >= k)
                bb.push_back(count);
            count = 0;
        }
    }
    for (auto vl : aa)
    {
        for (int i = 1; i <= vl; i++)
        {
            int x = (vl - i + 1)
            if()
            for (auto vl : bb)
            {

            }
        }
    }
    cerr << endl;
    for (auto vl : bb)
        cerr << vl <
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}