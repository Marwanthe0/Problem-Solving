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
string ans(int n)
{
    if (n <= 1)
        return "A";
    string k = ans(n - 1);
    return k + (char)('A' + n - 1) + k;
}
void marwan()
{
    int n;
    cin >> n;
    cout << ans(n) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}