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
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++, sum += vl;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int rem = sum - v[i];
        m[v[i]]--;
        if (m[v[i]] <= 0)
        {
            m.erase(v[i]);
        }
        if (rem % 2 == 0 && m.find(rem / 2) != m.end())
        {
            ans.push_back(i + 1);
        }
        m[v[i]]++;
    }
    cout << ans.size() << endl;
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}