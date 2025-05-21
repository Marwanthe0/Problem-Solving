#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
void marwan()
{
    int a, b, k;
    cin >> a >> b >> k;
    if (k >= max(a, b))
    {
        yes;
        return;
    }
    if (a == b)
    {
        if (k >= a)
            yes;
        else
            no;
        return;
    }
    if (k > min(a, b))
    {
        int x = max(a, b) - k;
        if (a > b)
            a = x;
        else
            b = x;
        if (max(a, b) > k)
            no;
        else
            yes;
        return;
    }
    int x = max(a, b) - k;
    if (a > b)
        a = x;
    else
        b = x;
    if (max(a, b) > k)
        no;
    else
        yes;
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