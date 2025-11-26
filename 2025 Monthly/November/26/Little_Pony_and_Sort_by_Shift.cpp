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
    if (is_sorted(all(v)))
    {
        cout << 0 << endl;
        return;
    }
    int mx = *max_element(all(v)), fo = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == mx)
        {
            fo = i;
            break;
        }
    for (int i = n - 1; i > fo; i--)
    {
        if (v[i] == mx)
            continue;
        if (v[i] > v[0])
        {
            cout << -1 << endl;
            return;
        }
        count++;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}