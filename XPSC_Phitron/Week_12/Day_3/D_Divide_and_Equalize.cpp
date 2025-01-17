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
    set<int> s;
    for (auto &vl : v)
    {
        cin >> vl;
        s.insert(vl);
    }
    if (s.size() == 1)
    {
        yes;
        return;
    }
    sort(all(v));
    int l = 0, r = n - 1;
    while (l < r)
    {
        // ll x = __gcd(v[l], v[r]);
        // if (x != 1)
        // {
        //     v[r] /= x, v[l] *= x;
        //     l++, r--;
        // }
        // else
        //     l++;
        ans.push_back(v[l++] * v[r--]);
    }
    
    cout << endl;
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