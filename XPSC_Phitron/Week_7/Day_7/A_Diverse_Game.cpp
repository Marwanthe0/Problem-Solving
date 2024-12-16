#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    if (n == 1 && m == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (m == 1)
    {
        if (n % 2 == 0)
            for (int i = n - 1; i >= 0; i--)
                cout << a[i][0] << endl;
        else
        {
            swap(a[n / 2][0], a[(n / 2) + 1][0]);
            for (int i = n - 1; i >= 0; i--)
                cout << a[i][0] << endl;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        reverse(a[i], a[i] + m);
    }
    if (m % 2)
    {
        for (int i = 0; i < n; i++)
        {
            swap(a[i][m / 2], a[i][(m / 2) + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
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