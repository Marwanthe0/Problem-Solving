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
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    if (n == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i && j == 0)
                    cout << 0 << " ";
                else
                    cout << 1 << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    else if (n == 4)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                {
                    cout << 1 << " ";
                }
                else
                {
                    if (i == 2 && j == 1)
                        cout << 1 << " ";
                    else
                    {
                        cout << 0 << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                {
                    cout << 1 << " ";
                }
                else
                {
                    if (i == 2)
                        cout << 1 << " ";
                    else
                    {
                        cout << 0 << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }
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