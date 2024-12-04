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
    vector<int> v(n), ans;
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i <= n; i++)
        if (abs(v[i - 1] - i))
            ans.push_back(abs(v[i - 1] - i));
    int x = ans[0];
    for (auto vl : ans)
    {
        x = min(x, __gcd(x, vl));
    }
    cout << x << endl;
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