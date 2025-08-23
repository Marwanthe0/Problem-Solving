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
    deque<char> s;
    string st;
    cin >> st;
    for (auto vl : st)
        s.push_back(vl);
    int m;
    cin >> m;
    string b, c;
    cin >> b >> c;
    int i = 0;
    for (auto vl : c)
    {
        if (vl == 'D')
            s.push_back(b[i++]);
        else
            s.push_front(b[i++]);
    }
    for (auto vl : s)
        cout << vl;
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