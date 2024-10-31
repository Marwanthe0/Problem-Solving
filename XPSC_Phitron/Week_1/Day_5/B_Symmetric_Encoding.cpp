#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (int i = 0; i < n; i++)
        m[s[i]]++;
    string r;
    for (auto vl : m)
        r.push_back(vl.first);
    map<char, char> a;
    for (int i = 0; i < r.size(); i++)
    {
        a[r[i]] = r[r.size() - i - 1];
    }
    for (int i = 0; i < s.size(); i++)
        s[i] = a[s[i]];
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