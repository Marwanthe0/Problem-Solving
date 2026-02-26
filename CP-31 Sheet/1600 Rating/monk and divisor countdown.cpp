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
    vector<int> v(n), mul(2e5 + 5, 0), hsh(2e5 + 5, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }
    for (int i = 2; i <= 2e5; i++)
    {
        for (int j = i; j <= 2e5; j += i)
        {
            mul[i] += hsh[j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << mul[x] + mul[y] - mul[(x * y) / __gcd(x, y)] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}