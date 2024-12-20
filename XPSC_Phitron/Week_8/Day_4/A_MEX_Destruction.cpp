#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll sum = accumulate(v.begin(), v.end(), 0);
    if (sum == 0)
    {
        cout << 0 << endl;
        return;
    }
    int idx = 0;
    while (!v[idx])
    {
        idx++;
    }
    int count = 0;
    for (int i = idx; i < n; i++)
    {
        if (v[i] == 0)
        {
            count++;
            while (i < n && v[i] == 0)
            {
                i++;
            }
        }
    }
    if (v[n - 1] == 0)
        count--;
    if (count == 0)
    {
        cout << 1 << endl;
        return;
    }
    else
        cout << 2 << endl;
    // cerr << count << endl;
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