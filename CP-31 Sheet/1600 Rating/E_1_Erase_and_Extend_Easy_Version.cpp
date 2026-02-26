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
string f(string &s, int k)
{
    string ans;
    for (int i = 0; i < k; i++)
        ans.push_back(s[i % s.size()]);
    return ans;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<string> ans;
    string s;
    cin >> s;
    string t;
    string last;
    for (int i = 0; i < k; i++)
        last.push_back('z');
    for (int i = 0; i < s.size(); i++)
    {
        t.push_back(s[i]);
        string temp = f(t, k);
        if (temp < last)
            last = temp;
    }
    cout << last << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}