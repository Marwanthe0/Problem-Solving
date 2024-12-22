#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, q;
    cin >> n;
    cin >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int mx = *max_element(v.begin(), v.end());
    mx = __lg(mx);
    mx = (1 << mx);
    vector<int> query(q);
    for (auto &vl : query)
        cin >> vl;
    vector<int> op;
    for (int i = 0; i < q; i++)
    {
        if (op.empty() && (1 << query[i]) <= mx)
        {
            op.push_back(query[i]);
        }
        else if (!op.empty() && query[i] < op.back())
        {
            op.push_back(query[i]);
        }
    }
    for (auto &vl : op)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] % (1 << vl) == 0)
                v[i] += (1 << (vl - 1));
        }
        // cout << vl << " ";
    }
    for (auto &vl : v)
        cout << vl << " ";
    // cout << mx << endl;
    cout << endl;
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