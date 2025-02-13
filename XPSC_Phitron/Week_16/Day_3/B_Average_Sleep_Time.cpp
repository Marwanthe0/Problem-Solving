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
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    long double sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (v[i] * min(min(k, (n - k) + 1), (min(i, (n - i) + 1))));
        cerr << min(min(k, (n - k) + 1), (min(i, (n - i) + 1))) << " ";
    }
    // cerr << endl;
    sum /= ((n - k) + 1);
    int sz = to_string((int)sum).size();
    cout << setprecision(sz + 10) << sum << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}