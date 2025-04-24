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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int cnt = -1;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            if (cnt != -1)
            {
                if (a[i] + b[i] != cnt)
                {
                    cout << 0 << endl;
                    return;
                }
            }
            else
                cnt = a[i] + b[i];
        }
        else
            t.push_back(a[i]);
        if (cnt != -1)
        {
            cout << 1 << endl;
            return;
        }
    }
    int mx = *max_element(all(t)), mn = *min_element(all(t));
    cout << k - (mx - mn) + 1 << endl;
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