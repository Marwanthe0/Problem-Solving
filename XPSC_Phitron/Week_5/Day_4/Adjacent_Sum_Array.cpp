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
    vector<int> v(n - 1), ans(n);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end());
    ans[0] = (v[0] / 2);
    ans[1] = (v[0] / 2) + (v[0] % 2);
    for (int i = 1; i < n; i++)
    {
        ans[i + 1] = v[i] - ans[i];
    }
    for (auto vl : ans)
        cout << vl << " ";
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