#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m, k;
    cin >> n >> m >> k;
    int p = 2 * (n + m);
    if (k <= 4)
    {
        cout << 4 - k << endl;
        return;
    }
    else if (k > p)
    {
        cout << k - p << endl;
        return;
    }
    else if (k % 2)
    {
        cout << 1 << endl;
        return;
    }
    cout << 0 << endl;
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