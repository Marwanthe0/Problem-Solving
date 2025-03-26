#include <bits/stdc++.h>
using namespace std;
#define int long double
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 2; i < n; i++)
    {
        if (v[i] * v[0] != v[1] * v[i - 1])
        {
            no;
            return;
        }
    }
    yes;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}