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
    int n, mn = INT_MIN;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
    {
        cin >> vl;
        mn = max(mn, vl);
        if (vl == mn)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
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