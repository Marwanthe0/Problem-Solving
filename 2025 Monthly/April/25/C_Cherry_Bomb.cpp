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
        if (b[i] == -1)
            t.push_back(a[i]);
        else
        {
            if (cnt == -1)
                cnt = a[i] + b[i];
            else if (cnt != a[i] + b[i])
            {
                cout << 0 << endl;
                return;
            }
        }
    }
    if (t.empty())
    {
        cout << 1 << endl;
        return;
    }
    if (t.size() != n)
    {
        if (*max_element(all(t)) > cnt || *min_element(all(t)) + k < cnt)
        {
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }
    else
        cout << k - (*max_element(all(t)) - *min_element(all(t))) + 1 << endl;
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