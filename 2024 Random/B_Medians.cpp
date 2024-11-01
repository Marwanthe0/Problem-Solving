#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1)
        cout << "1\n"
             << 1 << endl;
    else if (k == n || k == 1)
        cout << -1 << endl;
    else
    {
        ll x = 0;
        if (k % 2 == 0)
        {
            if ((n - k) % 2)
            {
                x = 3;
            }
            else
                x = 4;
        }
        else
        {
            if ((n - k) % 2)
            {
                x = 4;
            }
            else
                x = 5;
        }
        cout << x << endl;

        if (k % 2 == 0)
        {
            if ((n - k) % 2)
            {
                cout << 1 << " " << k << " " << k + 1 << endl;
            }
            else
            {
                cout << 1 << " " << k << " " << k + 1 << " " << k + 2 << endl;
            }
        }
        else
        {
            if ((n - k) % 2)
            {
                cout << 1 << " " << 2 << " " << k << " " << " " << k + 1 << endl;
            }
            else
            {
                cout << 1 << " " << 2 << " " << k << " " << k + 1 << " " << k + 2 << endl;
            }
        }
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