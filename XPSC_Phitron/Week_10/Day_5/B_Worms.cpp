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
    vector<int> v(n), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i - 1];
        pf[i] = pf[i - 1] + v[i - 1];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        cout << lower_bound(all(pf), x) - pf.begin() << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}