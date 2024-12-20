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
    int x = __lg(n);
    int count = 0, ans = 0;
    for (int i = x; i >= 0; i--)
    {
        if ((n >> i) & 1)
            count++;
        else if (count >= 2)
        {
            ans++;
        }
    }
    cout << (1 << ans) << endl;
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