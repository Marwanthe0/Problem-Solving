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
int mxd(int n)
{
    string x = to_string(n);
    int y = 0;
    for (auto c : x)
    {
        y = max(y, (int)(c - '0'));
    }
    return y;
}
void marwan()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        n -= mxd(n);
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