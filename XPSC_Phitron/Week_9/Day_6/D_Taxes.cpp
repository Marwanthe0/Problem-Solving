#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            ans++;
            if (n / i != i)
                ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}