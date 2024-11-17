#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll a, b, c, s;
    cin >> a >> b >> c >> s;
    if (s > ((a * c) + b))
    {
        no;
        return;
    }
    else
    {
        if (s % c > b)
            no;
        else
            yes;
    }
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