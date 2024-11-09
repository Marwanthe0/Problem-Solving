#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> v(m);
    for (auto &vl : v)
        cin >> vl;
    // for (auto vl : v)
    //     cout << vl << " ";
    sort(v.begin(), v.end());
    while (q--)
    {
        int x;
        cin >> x;
        if (x < *v.begin())
        {
            cout << *v.begin() - 1 << endl;
        }
        else if (x > v.back())
        {
            cout << n - v.back() << endl;
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), x);
            if (*it == x)
                cout << 0 << endl;
            else
            {
                cout << (*it - *(it - 1)) / 2 << endl;
            }
        }
    }
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