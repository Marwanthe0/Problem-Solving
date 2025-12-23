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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        if (v.empty())
            v.push_back(vl);
        else if (v.back() != vl)
            v.push_back(vl);
    }
    set<int> s;
    for (auto vl : v)
        s.insert(vl);
    if (s.size() == 1)
    {
        cout << 1 << endl;
        return;
    }
    bool flag = v[1] >= v[0];
    int count = 2;
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] >= v[i - 1] != flag)
        {
            count++, flag = v[i] > v[i - 1];
        }
    }
    cout << count << endl;
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