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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int x;
        if (a % i == 0)
        {
            x = (a / i) * i;
        }
        else
            x = i * ((a / i) + 1);
        if (x > b)
        {
            no;
            return;
        }
        ans.push_back(x);
    }
    yes;
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
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