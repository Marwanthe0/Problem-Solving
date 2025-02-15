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
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            v.push_back(i);
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    if (v.size() & 1)
    {
        int mid = v[v.size() / 2];
        int count = 1, ans = 0;
        for (int i = 0; i < (v.size() / 2); i++)
        {
            ans += ((mid - count) - v[i]), count++;
        }
        count = 1;
        for (int i = (v.size() / 2) + 1; i < v.size(); i++)
        {
            ans += v[i] - (mid + count);
            count++;
        }
        cout << ans << endl;
    }
    else
    {
        int mid = v[v.size() / 2];
        int count = 1, ans = 0;
        for (int i = 0; i < v.size() / 2; i++)
        {
            ans += ((mid - count) - v[i]), count++;
        }
        count = 1;
        for (int i = (v.size() / 2) + 1; i < v.size(); i++)
        {
            ans += v[i] - (mid + count);
            count++;
        }
        mid = v[(v.size() / 2) - 1];
        count = 1;
        int ans2 = 0;
        for (int i = 0; i < (v.size() / 2) - 1; i++)
        {
            ans2 += ((mid - count) - v[i]), count++;
        }
        count = 1;
        for (int i = v.size() / 2; i < v.size(); i++)
        {
            ans2 += v[i] - (mid + count);
            count++;
        }
        cout << min(ans, ans2) << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}