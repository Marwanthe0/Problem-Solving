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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
struct seg
{
    int s, e, z, o, i;
};

void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<seg> v(m), v2;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].s >> v[i].e;
        v[i].z = (v[i].e - v[i].s + 1), v[i].o = 0;
        v[i].i = i;
    }
    v2 = v;
    sort(all(v), [&](seg a, seg b)
         {if(a.s == b.s) return a.e < b.e; return a.s < b.s; });
    sort(all(v2), [&](seg a, seg b)
         {if(a.e == b.e) return a.s < b.s; return a.e < b.e; });
    // for (auto sg : v)
    //     cerr << sg.s << " " << sg.e << endl;
    // cerr << endl;
    // for (auto sg : v2)
    //     cerr << sg.s << " " << sg.e << endl;
    // cerr << endl;
    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i];
    }
    vector<int> tv;
    for (auto x : v2)
        tv.push_back(x.e);
    int idx = 0;
    for (int idx2 = 0; idx2 < queries.size(); idx2++)
    {
        int x = queries[idx2];
        set<int> s;
        for (auto segs : v)
        {
            if (segs.s <= x)
                s.insert(segs.i);
            else
                break;
        }
        int idx = (lower_bound(all(tv), x) - tv.begin());
        for (int i = idx; i < v2.size(); i++)
        {
            if (v2[i].e >= x && s.count(v2[i].i))
            {
                v2[i].z--, v2[i].o++;
                if (v2[i].o > v2[i].z)
                {
                    cout << idx2 + 1 << endl;
                    return;
                }
            }
        }
    }
    minus;
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