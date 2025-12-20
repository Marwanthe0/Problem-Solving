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
    vector<int> a(n), v(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : v)
        cin >> vl;
    int count = 1, mx = INT_MIN, first = 1, last = 1, cnt = 0, mncnt = INT_MAX;
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (v[i] >= v[i - 1])
        {
            count++;
            if (a[i] != v[i])
                flag = true;
        }
        else
        {
            if (count > mx && flag)
            {
                mx = count;
                last = i;
                first = (i - count + 1);
            }
            flag = false;
            count = 1;
        }
    }
    if (count > mx && flag)
    {
        mx = count;
        last = n;
        first = (n - count + 1);
    }
    cout << first << " " << last << endl;
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