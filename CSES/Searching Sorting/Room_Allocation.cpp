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
    vector<pair<int, int>> v(n);
    map<int, set<int>> m;
    for (int i = 0; i < n; i++)
    {
        auto &[x, y] = v[i];
        cin >> x >> y;
        m[x].insert(i + 1);
        m[y + 1].insert(-(i + 1));
    }
    set<int> s, khali;
    int mx = 1, count = 1;
    vector<int> room(n + 1, 0);
    for (auto &[x, y] : m)
    {
        //cerr << x << endl;
        for (auto &vl : y)
        {
            //cerr << vl << " ";
            if (vl > 0)
            {
                s.insert(vl);
                if (khali.empty())
                    room[vl] = count++;
                else
                {
                    room[vl] = *khali.begin();
                    khali.erase(khali.begin());
                }
            }
            else
            {
                s.erase(-vl);
                khali.insert(room[-vl]);
            }
        }
        //cerr << endl;
        mx = max(mx, (int)s.size());
    }
    cout << mx << endl;
    for (int i = 1; i <= n; i++)
        cout << room[i] << " ";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}