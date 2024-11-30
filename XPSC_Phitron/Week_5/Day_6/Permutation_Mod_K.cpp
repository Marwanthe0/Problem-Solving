#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    if (k == 1 || (n % 2 == 1 && k == 2))
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back(i);
    }
    ans.push_back(1);
    if (n % k == 1)
    {
        swap(ans[n - 1], ans[1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cerr << (i % k != ans[i - 1] % k) << " ";
    }
    cerr << endl;
    for (auto &vl : ans)
        cout << vl << " ";
    cerr << endl;
    cout << endl;
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