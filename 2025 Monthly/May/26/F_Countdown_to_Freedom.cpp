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
int dig(int n)
{
    int c = 0;
    while (n)
        c += n % 10, n /= 10;
    return c;
}
void marwan()
{
    int a, b, k, count = 0;
    cin >> a >> b >> k;
    for (int i = a; i <= b; i++)
    {
        if (dig(i) % k == 0)
            count++;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}