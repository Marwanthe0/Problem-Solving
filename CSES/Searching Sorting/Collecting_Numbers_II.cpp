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
    vector<int> v(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        v[x] = i;
    }
    v[0] = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] < v[i - 1])
            ans++;
    }
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        if (i > j)
            swap(i, j);
        // for jth value
        int posofjm1 = v[a[j] - 1], posofjp1 = v[a[j] + 1];
        if (a[j] != 1 && posofjm1 > i && posofjm1 < j)
        {
            ans++;
        }
        if (a[j] != n && posofjp1 > i && posofjp1 < j)
            ans--;
        // for ith value
        int posofim1 = v[a[i] - 1], posofip1 = v[a[i] + 1];
        if (a[i] != 1 && posofim1 > i && posofim1 < j)
        {
            ans--;
        }
        if (a[i] != n && posofip1 > i && posofip1 < j)
            ans++;
        if (a[i] - a[j] == 1)
            ans--;
        if (a[i] - a[j] == -1)
            ans++;
        swap(v[a[i]], v[a[j]]);
        swap(a[i], a[j]);
        cout << ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}