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
    int n, a, b;
    cin >> n >> a >> b;
    int x = n, c = a, d = b;
    while (x > 0)
    {
        if (a <= 0 && b <= 0)
            break;
        int op1 = x / 2, op2 = (x / 2) + (x % 2);
        if (op2 > op1)
        {
            if (a > 0)
                x = op1, a--;
            else
                x = op2, b--;
        }
        else
        {
            if (b > 0)
                x = op2, b--;
            else
                x = op1, a--;
        }
    }
    while (n > 0)
    {
        if (c <= 0 && d <= 0)
            break;
        int op1 = n / 2, op2 = (n / 2) + (n % 2);
        if (op1 < op2)
        {
            if (n == 1)
                d = 0;
            if (d > 0)
                n = op2, d--;
            else
            {
                n = op1, c--;
            }
        }
        else
        {
            if (c > 0)
                n = op1, c--;
            else if (n == 1)
                d = 0;
            else if (d > 0)
                n = op2, d--;
        }
    }
    cout << x << " " << n << endl;
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