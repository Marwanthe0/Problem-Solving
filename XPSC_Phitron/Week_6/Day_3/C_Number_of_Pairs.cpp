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
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        int range1 = (l - x), range2 = (r - x);
        int shuru = lower_bound(v.begin(), v.end(), range1) - v.begin(), shesh = upper_bound(v.begin(), v.end(), range2) - v.begin();
        shuru = max(shuru, i + 1);
        shuru++, shesh++;
        cerr << shuru << " " << shesh << endl;
        if (shesh > shuru)
            ans += (shesh - shuru);
    }
    cerr << endl;
    cout << ans << endl;
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