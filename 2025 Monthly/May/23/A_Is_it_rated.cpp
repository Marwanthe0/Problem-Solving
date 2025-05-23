#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    int a, b;
    cin >> a >> b;
    if (a >= 1600 && a <= 2399)
    {
        yes;
        return;
    }
    if (a >= 1200 && a <= 2399)
    {
        if (b == 1)
            no;
        else
            yes;
        return;
    }
    if (a >= 1600 && a <= 2999)
    {

        if (b == 2)
            no;
        else
            yes;
        return;
    }
    no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}