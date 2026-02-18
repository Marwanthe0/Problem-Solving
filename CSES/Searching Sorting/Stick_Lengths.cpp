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
    sort(all(v));
    int ave = v[n / 2], ave2 = v[n / 2 + 1], sum = 0ll, sum2 = 0ll;
    for (auto vl : v)
    {
        sum += abs(vl - ave);
        sum2 += abs(vl - ave2);
    }
    cout << min(sum, sum2) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}