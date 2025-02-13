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
    vector<int> dif;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            dif.push_back(v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    sort(all(dif));
    int x = dif.size() + 1, ans = 0, sum = 0;
    for (auto &vl : dif)
    {
        int temp = vl;
        vl -= sum;
        ans += max(0ll, (x * vl));
        sum = temp;
        x--;
        // cout << vl << " ";
    }
    cout << ans << endl;
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