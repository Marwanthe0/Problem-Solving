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
    int ans = 0;
    for (auto c : s)
        m[c]++;
    for (auto vl : m)
    {
        cerr << vl.first << " " << vl.second;
        if (vl.second >= (vl.first - 'A' + 1))
            ans++;
    }
    cerr << endl;
    cout
        << ans << endl;
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