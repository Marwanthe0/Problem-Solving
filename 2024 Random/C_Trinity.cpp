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
    sort(v.begin(), v.end());
    int ans = 0;
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] + v[i + 1] > v.back())
        {
            ans = i;
            break;
        }
    }
    cout << min(ans, n - 1 - ans) << endl;
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