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
int mx(int n)
{
    int x = 0ll;
    while (n--)
    {
        x *= 10ll;
        x += 9ll;
    }
    return x;
}
void marwan()
{
    int n, count = 0;
    cin >> n;
    while (n > 0)
    {
        int x = mx((int)to_string(n).size() - 1ll);
        if ((int)to_string(n - 1).size() & 1ll)
            count += (int)n - (int)x;
        n = (int)x;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}