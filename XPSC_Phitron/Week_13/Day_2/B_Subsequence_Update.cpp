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
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n), w;
    for (auto &vl : v)
        cin >> vl;
    ll sum = 0;
    // for (int i = l; i <= r; i++)
    //     w.push_back(v[l - 1]);
    for (auto vl : v)
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