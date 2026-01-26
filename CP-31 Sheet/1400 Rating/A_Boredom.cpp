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
void marwan()
{
    int n;
    cin >> n;
    unordered_map<int, int> v;
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x]++;
        mx = max(mx, x);
    }
    int prev1 = 0, prev2 = 0, cur = 0;
    for (int i = 1; i <= mx; i++)
    {
        int nibona = prev1, nibo = i * v[i];
        if (i > 1)
            nibo += prev2;
        cur = max(nibo, nibona);
        prev2 = prev1, prev1 = cur;
    }
    cout << cur << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}