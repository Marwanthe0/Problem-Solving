#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), pf(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    set<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(v[i]);
        pf[i] = s.size();
    }
    while (m--)
    {
        int x;
        cin >> x;
        cout << pf[x - 1] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}