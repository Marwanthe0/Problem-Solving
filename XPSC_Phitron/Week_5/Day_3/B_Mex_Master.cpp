#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    int z = 0;
    bool f = false;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            z++;
        }
        else if (x >= 2)
        {
            f = true;
        }
    }
    if (z <= (n + 1) / 2)
    {
        cout << "0\n";
    }
    else if (f || z == n)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
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