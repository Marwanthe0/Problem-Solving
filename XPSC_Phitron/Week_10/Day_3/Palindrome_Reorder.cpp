#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    int count = 0;
    char odd;
    for (auto vl : m)
    {
        if (vl.second & 1)
        {
            count++;
            odd = vl.first;
        }
        if (count > 1)
        {
            cout << "NO SOLUTION\n";
            return;
        }
    }
    string ans;
    for (auto vl : m)
    {
        for (int i = 0; i < vl.second / 2; i++)
        {
            ans.push_back(vl.first);
        }
    }
    cout << ans;
    if (count)
        cout << odd;
    reverse(all(ans));
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}