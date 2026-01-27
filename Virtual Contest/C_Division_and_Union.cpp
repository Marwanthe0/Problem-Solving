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
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(all(v));
    int mx = INT_MIN, count = 0, ans = 0;
    for (auto vl : v)
    {
        int x = vl.first.first, y = vl.first.second;
        if (mx != INT_MIN && mx < x)
        {
            ans = count;
            break;
        }
        mx = max(mx, y);
        count++;
    }
    if (ans)
    {
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            if (i < ans)
            {
                answer[v[i].second] = 1;
            }
            else
                answer[v[i].second] = 2;
        }
        for (auto vl : answer)
            cout << vl << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
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