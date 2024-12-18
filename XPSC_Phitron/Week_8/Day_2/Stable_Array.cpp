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
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]] = max(m[v[i]], i);
    }
    int ans = INT_MIN;
    priority_queue<int> pq;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!pq.empty())
        {
            if (pq.top() > v[i])
            {
                ans = max(ans, m[pq.top()]);
            }
        }
        pq.push(v[i]);
    }
    if (ans > 0)
        cout << ans << endl;
    else
        cout << 0 << endl;
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