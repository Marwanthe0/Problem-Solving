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
int rnd(int a, int b)
{
    if (a + 1 > b)
        return 1;
    else
        return ++a;
}
void marwan()
{
    int n;
    cin >> n;
    int a[n + 1][n + 1], c = (n - ((n / 2) - 1));
    for (int i = 1; i <= n; i++)
    {
        int x = c;
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = x;
            cout << x << " ";
            x = rnd(x, n);
        }
        cout << endl;
        c = rnd(c, n);
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