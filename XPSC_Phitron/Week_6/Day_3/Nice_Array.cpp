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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int x = 0, y = 0;
    for (auto &vl : v)
    {
        if (vl % k)
        {
            if (vl >= 0)
                x++;
            else
                y++;
        }
        vl = vl / k;
    }
    ll sum = accumulate(v.begin(), v.end(), 0);
    // cerr << sum << " " << x << " " << y << endl;
    if ((0 >= sum - y) && (0 <= sum + x))
        yes;
    else
        no;
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