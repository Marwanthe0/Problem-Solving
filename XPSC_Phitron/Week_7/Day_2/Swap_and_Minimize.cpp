#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> w(v);
    sort(w.begin(), w.end());
    int l = 0, r = 0, mn = INT_MAX, sum = 0;
    while (l < r)
    {
        sum += v[r];
        if (r - l + 1 == 0)
        {
            mn = min(sum, mn);
            sum -= v[l];
            l++;
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