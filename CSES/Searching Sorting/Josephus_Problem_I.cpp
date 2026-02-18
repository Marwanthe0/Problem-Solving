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
void jos(vector<int> &v, vector<int> &nv)
{
    int n = v.size();
    if (n == 1)
    {
        cout << v[0] << endl;
        return;
    }
    for (int i = 1; i < n; i += 2)
        cout << v[i] << " ";
    if (n & 1)
    {
        nv.push_back(v[n - 1]);
        for (int i = 0; i < n - 1; i += 2)
        {
            nv.push_back(v[i]);
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
            nv.push_back(v[i]);
    }
    v = nv;
    nv.clear();
    jos(v, nv);
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), nv;
    for (int i = 1; i <= n; i++)
        v[i - 1] = i;
    jos(v, nv);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}