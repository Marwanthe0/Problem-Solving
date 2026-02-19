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
    vector<int> v(n);
    map<int, int> m;
    m[0] = 1;
    int sum = 0, count = 0;
    for (auto &vl : v)
    {
        cin >> vl;
        sum += vl;
        if (m.count(sum - k))
            count += m[sum - k];
        m[sum]++;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}