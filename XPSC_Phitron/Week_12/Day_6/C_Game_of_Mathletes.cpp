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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (auto &vl : v)
        cerr << vl << " ";
    cerr << endl;
    int l = 0, r = n - 1, ans = 0;
    while (l < r)
    {
        if (v[l] + v[r] == k)
            ans++, l++, r--;
        else if (v[l] + v[r] > k)
            r--;
        else
            l++;
    }
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