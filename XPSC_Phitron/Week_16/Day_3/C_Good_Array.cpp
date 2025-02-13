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
    vector<int> v(n);
    map<int, int> m;
    forn
    {
        cin >> v[i];
        m[v[i]]++;
    }
    int sum = accumulate(all(v), 0ll);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int target = (sum - v[i]);
        if (target & 1)
            continue;
        else
            target /= 2;
        m[v[i]]--;
        if (m.find(target) != m.end() && m[target])
            ans.push_back(i + 1);
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