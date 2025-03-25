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
bool cmp(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b) { return a.second.second > b.second.second; }
void marwan()
{
    int n;
    cin >> n;
    string pass;
    cin >> pass;
    vector<pair<int, pair<string, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        v[i].first = i + 1;
        v[i].second.first = x;
        v[i].second.second = 0;
    }
    // for (auto vl : v)
    //     cout << vl.second.first << endl;
    // cout << endl;
    int q;
    cin >> q;
    while (q--)
    {
        string op;
        cin >> op;
        if (op == "bonus")
        {
            int id, score;
            string trypass;
            cin >> id >> score >> trypass;
            if (trypass == pass)
            {
                cout << "Updated successfully" << endl;
                v[id - 1].second.second += score;
            }
            else
                cout << "Wrong password please try again" << endl;
        }
        else
        {
            auto t = v;
            sort(all(t), cmp);
            int count = 0, last = -1;
            for (auto vl : t)
            {
                if (vl.second.second <= 0)
                    break;
                if (vl.second.second != last)
                {
                    count++;
                }
                cout << count << " " << vl.first << " " << vl.second.first << " " << vl.second.second << endl;
                last = vl.second.second;
            }
        }
        cout << "---" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}