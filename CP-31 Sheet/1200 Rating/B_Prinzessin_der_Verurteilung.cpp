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
    string s;
    cin >> s;
    // n = s.size();
    multiset<string> ms;
    vector<string> v = {""};
    for (int i = 0; i < 26; i++)
    {
        vector<string> t;
        for (auto vl : v)
        {
            for (int x = 0; x < n; x++)
            {
                string temp = "";
                for (int j = x; j < min((int)n, (int)(x + vl.size() + 1)); j++)
                {
                    temp += s[j];
                }
                ms.insert(temp);
            }
            for (char c = 'a'; c <= 'z'; c++)
            {
                t.push_back(vl + c);
                if (ms.find(vl + c) == ms.end())
                {
                    cout << vl + c << endl;
                    return;
                }
                // cerr << vl + c << " ";
            }
        }
        v = t;
        // cerr << endl;
    }
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