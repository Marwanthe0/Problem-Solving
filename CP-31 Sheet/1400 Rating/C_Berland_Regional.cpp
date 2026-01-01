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
    vector<int> a(n), b(n);
    map<int, pair<int, vector<int>>> m;
    map<int, int> fre;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        fre[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        m[a[i]].second.push_back(b[i]);
        m[a[i]].first += b[i];
    }
    vector<vector<int>> st;
    for (auto &[x, y] : m)
    {
        sort(all(y.second));
        for (int i = 1; i < y.second.size(); i++)
        {
            y.second[i] += y.second[i - 1];
            // cout << y.second[i] << " ";
        }
        st.push_back(y.second);
        // cout << endl;
    }
    sort(all(st), [&](vector<int> a, vector<int> b)
         { return a.size() > b.size(); });
    // cout << endl;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int ans = 0ll;
        if (flag)
        {
            for (auto &v : st)
            {
                if (v.size() < i)
                {
                    break;
                }
                else
                {
                    int rem = (v.size() % i), sum = v.back();
                    if (rem > 0)
                    {
                        sum -= v[rem - 1];
                    }
                    ans += sum;
                }
            }
        }
        if (ans == 0)
        {
            flag = false;
        }
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