#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    stack<pair<int, char>> a, b;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b')
        {
            if (!a.empty())
            {
                a.pop();
            }
        }
        else if (s[i] == 'B')
        {
            if (!b.empty())
            {
                b.pop();
            }
        }
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                a.push({i, s[i]});
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                b.push({i, s[i]});
            }
        }
    }
    map<int, char> m;
    while (!a.empty())
    {
        m[a.top().first] = a.top().second;
        a.pop();
    }
    while (!b.empty())
    {
        m[b.top().first] = b.top().second;
        b.pop();
    }
    for (auto vl : m)
        cout << vl.second;
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