#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "yes" << endl
#define no cout << "no" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (is_sorted(all(v)))
    {
        yes;
        cout << 1 << " " << 1 << endl;
        return;
    }
    int l = -1, r = -1;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1] && l == -1)
        {
            l = i - 1;
            flag = true;
        }
        if (flag && (v[i] > v[i - 1]))
        {
            r = i - 1;
            flag = false;
        }
        else if (flag && i == n - 1)
            r = i;
    }
    // cerr << l << " " << r << endl;
    reverse(v.begin() + l, v.begin() + r + 1);
    // for (auto vl : v)
    //     cerr << vl << " ";
    if (is_sorted(all(v)))
    {
        yes;
        cout << l + 1 << " " << r + 1 << endl;
    }
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}