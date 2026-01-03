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
int d(int n)
{
    int sum = 0, x = n;
    while (x)
    {
        sum += (x % 10) * (x % 10);
        x /= 10;
    }
    return sum;
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 0; i < 10000; i++)
    {
        n = d(n);
        if (n == 1)
        {
            yes;
            return;
        }
    }
    no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}