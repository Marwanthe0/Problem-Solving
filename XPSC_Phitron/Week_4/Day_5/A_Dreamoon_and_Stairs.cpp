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
    if (n < m)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (int i = (n / 2) + (n % 2); i <= n; i++)
            if (i % m == 0)
            {
                cout << i << endl;
                return;
            }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}