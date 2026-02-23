#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool f(int i, int j, vector<string> &v)
{

    if (i < n - 1)
        f(i + 1 + (v[i][j] ==), j, v);
    if (j < n - 1)
        f(i, j + 1, v);
    if (i > 0)
        f(i - 1, j, v);
    if (v[i][j] == '>')
        j++;
    else
        j--;
}
void marwan()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (f(0, 0, v))
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}