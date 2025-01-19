#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (is_sorted(all(v)))
    {
        yes;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x = min(v[i], v[i + 1]);
        v[i] -= x, v[i + 1] -= x;
    }
    if (is_sorted(all(v)))
        yes;
    else
        no;
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
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