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
void marwan()
{
    int a[5];
    cin >> a[0] >> a[1] >> a[3] >> a[4];
    a[2] = a[1] + a[0];
    int count = 0, ans = INT_MIN;
    for (int i = 2; i < 5; i++)
    {
        if (a[i] == a[i - 1] + a[i - 2])
            count++;
    }
    ans = max(ans, count);
    count = 0, a[2] = a[3] - a[1];
    for (int i = 2; i < 5; i++)
    {
        if (a[i] == a[i - 1] + a[i - 2])
            count++;
    }
    ans = max(ans, count);
    cout << ans << endl;
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