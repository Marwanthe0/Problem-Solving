#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll count = b - 1;
    for (auto vl : v)
        count += min(vl, a);
    cout << count << endl;
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