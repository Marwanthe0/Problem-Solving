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
    int n;
    cin >> n;
    vector<int> v(n), ans;
    for (auto &vl : v)
        cin >> vl;
    ans.push_back(v.back());
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > ans.back())
        {
            if (v[i] >= 10)
                ans.push_back(v[i] % 10), ans.push_back(v[i] / 10);
            else
                ans.push_back(v[i]);
        }
        else
            ans.push_back(v[i]);
    }
    reverse(all(ans));
    if (is_sorted(all(ans)))
        yes;
    else
        no;
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