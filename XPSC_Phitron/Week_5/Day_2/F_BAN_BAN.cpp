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
    int x = (n / 2) + (n % 2);
    int l = 1, r = 3 * n;
    cout << x << endl;
    for (int i = 0; i < x; i++)
    {
        cout << l << " " << r << endl;
        l += 3;
        r -= 3;
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