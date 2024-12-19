#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for (auto &vl : v)
        cin >> vl;
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            if (((v[i] >> j) & 1) ^ ((x >> j) & 1))
                count++;
        }
        if (count <= k)
            ans++;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}