#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    string s;
    cin >> s;
    int one = 0;
    vector<pair<int, int>> o;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            one++;
        }
    }
    int lim = n - one;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' && v[i] <= lim)
            o.push_back({i, v[i]});
    }
    vector<pair<int, int>> bigs;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && v[i] > lim)
            bigs.push_back({i, v[i]});
    }
    sort(bigs.begin(), bigs.end(), cmp);
    reverse(bigs.begin(), bigs.end());
    for (auto vl : bigs)
        cerr << vl.first << "::" << vl.second << " ";
    // for (auto it = bigs.rbegin(); it != bigs.rend(); it--)
    //     cerr << it->first << "::" << it->second << " ";
    sort(o.begin(), o.end(), cmp);
    auto it = bigs.begin();
    for (auto &vl : o)
    {
        if (it == bigs.end())
            break;
        else
            swap(v[it->first], v[vl.first]);
        it++;
        cerr << vl.first << "::" << vl.second << " ";
    }
    cerr << endl;
    for (auto vl : v)
        cout << vl << " ";
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