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
    int x = (n / 2) * ((n / 2) + (n % 2 != 0));
    for (int i = 0; i < n - 1; i++)
    {
        int l, r;
        cin >> l >> r;
    }
    cout << x - (n - 1) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}