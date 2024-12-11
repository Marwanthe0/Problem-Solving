#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int x = 0;
    sort(v.begin(), v.end());
    for (auto vl : v)
        x ^= vl;
    if (x >= l && x <= r)
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