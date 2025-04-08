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
void marwan()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(all(a)), sort(all(b));
    if (b.empty())
    {
        cout << a.back() << endl;
        return;
    }
    else if (a.empty())
    {
        cout << b.back() << endl;
        return;
    }
    int last = a.back(), sum = accumulate(all(b), 0ll);
    a.pop_back();
    for (auto vl : a)
    {
        sum = (sum + vl) - 1;
    }
    cout << sum + last << endl;
}
int32_t main()
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