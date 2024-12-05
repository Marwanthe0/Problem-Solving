#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    vector<pair<char, int>> v;
    for (auto c : s)
    {
        m[c]++;
    }
    for (auto vl : m)
    {
        v.push_back(vl);
    }
    sort(v.begin(), v.end(), cmp);
    char x = v.begin()->first, y = v.rbegin()->first;
    // cout << x << " " << y << endl;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == y)
        {
            s[i] = x;
            break;
        }
    }
    cout << s << endl;
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