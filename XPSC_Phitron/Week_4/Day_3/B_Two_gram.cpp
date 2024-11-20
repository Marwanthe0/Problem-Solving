#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
string sr(char x, char y)
{
    string xs;
    xs += x;
    xs += y;
    return xs;
}
void marwan()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<pair<char, char>, int> m;
    for (int i = 0; i < n - 1; i++)
    {
        m[{s[i], s[i + 1]}]++;
    }
    int oc = INT_MIN;
    string ans;
    ans += m.begin()->first.first;
    ans += m.begin()->first.second;
    for (auto xs : m)
    {
        if (xs.second > oc)
        {
            oc = xs.second;
            string tmp;
            tmp += xs.first.first;
            tmp += xs.first.second;
            ans = tmp;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}