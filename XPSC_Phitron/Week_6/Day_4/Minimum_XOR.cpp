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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = INT_MAX, sum = v[0];
    for (int i = 1; i < n; i++)
    {
        sum ^= v[i];
    }
    ans = min(sum, ans);
    for (auto vl : v)
    {
        ans = min(sum ^ vl, ans);
    }
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