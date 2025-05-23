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
bool holds(multiset<int> ms, int n, int m)
{
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }
    reverse(all(v));
    int count = 0;
    for (auto vl : v)
    {
        bool flag = true;
        for (int i = 1; i <= m; i++)
        {
            if (mp[i] <= 0)
            {
                cout << count << endl;
                return;
            }
        }
        count++, mp[vl]--;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}