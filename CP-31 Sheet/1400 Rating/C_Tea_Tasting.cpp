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
void marwan()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), pr, df(n + 1, 0), df2(n + 1, 0);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
    {
        cin >> vl;
        if (pr.size())
            pr.push_back(pr.back() + vl);
        else
            pr.push_back(vl);
    }
    for (int i = 0; i < n; i++)
    {
        int target = a[i] + (i ? pr[i - 1] : 0);
        auto it = lower_bound(all(pr), target);
        int idx = it - pr.begin();
        if (idx == n)
        {
            df[i]++, df[idx]--;
        }
        else if (target != pr[idx])
        {
            df[i]++, df[idx]--, df2[idx] += target - (idx ? pr[idx - 1] : 0);
        }
        else
        {
            df[i]++, df[idx + 1]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            df[i] += df[i - 1];
        cout << df[i] * b[i] + df2[i] << " ";
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