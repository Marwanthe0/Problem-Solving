#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, x, y;
    cin >> n;
    int cnt = 0;
    vector<int> v(2 * n);
    for (auto &vl : v)
    {
        cin >> vl;
        if (!vl)
            cnt++;
    }
    sort(v.begin(), v.end());
    if (cnt % 2 == 0)
        x = 0, y = min(cnt, (2 * n) - cnt);
    else
    {
        x = 1, y = min(cnt, (2 * n) - cnt);
    }
    cout << x << " " << y << endl;
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