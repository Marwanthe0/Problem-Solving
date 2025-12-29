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
    map<int, int> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
    }
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x] = i;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[v[i]] < mx)
            count++;
        mx = max(mx, m[v[i]]);
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}