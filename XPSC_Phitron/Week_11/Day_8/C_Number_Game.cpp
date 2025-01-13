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
#define no cout << "NO" << endl
string a = "Ashishgup", f = "FastestFinger";
#define ash cout << a << endl
#define fas cout << f << endl
int ans(int n, int idx)
{

    if (n == 1)
        return idx;
    else if (n & 1 || n == 2)
        return idx + 1;
    else
    {
        for (int i = sqrt(n); i >= 3; i--)
        {
            if (n % i == 0 && ((n / i) % 2) != (i % 2))
            {
                return idx + 1;
            }
        }
        return idx;
    }
}
void marwan()
{
    int n;
    cin >> n;
    if (ans(n, 0) & 1)
        ash;
    else
        fas;
    // cout << ans(n, 0) << endl;
}
int main()
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