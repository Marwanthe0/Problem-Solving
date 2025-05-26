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
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for (auto c : s)
        if (c == '0')
            zero++;
        else
            one++;
    int ex = ((abs(zero - one) / 2) + (abs(zero - one) % 2 != 0));
    if (k < ex)
    {
        no;
        return;
    }
    if (k == ex)
    {
        yes;
        return;
    }
    if ((k - ex) % 2 == 0 && (k - ex) <= (zero / 2 + one / 2))
    {
        yes;
        return;
    }
    else
        no;
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