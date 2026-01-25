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
    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    vector<vector<int>> dvs(n + 1);
    for (int d = 1; d <= n; d++)
        for (int m = d; m <= n; m += d)
            dvs[m].push_back(d);

    if (s.count(1))
        cout << 1 << " ";
    else
        cout << -1 << " ";

    for (int i = 2; i <= n; i++)
    {
        vector<int> &divs = dvs[i];
        vector<int> avail;
        for (int d : divs)
            if (d != 1 && s.count(d))
                avail.push_back(d);
        if (avail.empty())
        {
            cout << -1 << " ";
            continue;
        }
        unordered_map<int, int> idx;
        idx.reserve(divs.size() * 2);
        for (int k = 0; k < (int)divs.size(); k++)
            idx[divs[k]] = k;
        vector<int> dist(divs.size(), -1);
        int start = idx[1];
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int curi = q.front();
            q.pop();
            int curv = divs[curi];
            for (int d : avail)
            {
                long long nxtv = 1LL * curv * d;
                if (nxtv > i)
                    continue;
                if (i % (int)nxtv != 0)
                    continue;
                int nxti = idx[(int)nxtv];
                if (dist[nxti] == -1)
                {
                    dist[nxti] = dist[curi] + 1;
                    q.push(nxti);
                }
            }
            if (dist[idx[i]] != -1)
                break;
        }
        int ans = dist[idx[i]];
        if (ans == -1)
            cout << -1 << " ";
        else
            cout << ans << " ";
    }
    cout << endl;
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
