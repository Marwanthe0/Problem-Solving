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
    vector<int> v(5);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    int sum = accumulate(all(v), 0ll);
    int count = 0, s = 0;
    if (sum / 5 >= 7)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if ((sum / 5) < 7)
        {
            sum -= v[i], sum += 10, count += 100;
        }
        else
        {
            cout << count << endl;
            return;
        }
    }
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