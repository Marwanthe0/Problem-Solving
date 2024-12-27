#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
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
    vector<int> a(n), b(n), c(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        c[i] = b[i] - a[i];
    }
    sort(all(c));
    for (auto vl : c)
        cerr << vl << " ";
    cerr << endl;
    int count = 0;
    if (c[0] >= 0)
    {
        cout << n / 2 << endl;
        return;
    }
    int l = 0, r = n - 1;
    while (l < r)
    {
        while (l < r && abs(c[l]) > c[r])
            l++;
        if (l < r && abs(c[l]) <= c[r])
            count++;
        l++, r--;
    }
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