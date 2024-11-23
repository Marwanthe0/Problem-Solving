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
    int n = s.size();
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    if (n == 1 || (m.size() == 2 && (n == 2)))
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cout << s[i - 1] << s[i] << endl;
            return;
        }
    }
    map<char, int> last;
    int l = 0, r = 2;
    last[s[0]]++, last[s[1]]++;
    while (r < n)
    {
        last[s[r]]++;
        if (last.size() == 3)
        {
            cout << s[r - 2] << s[r - 1] << s[r] << endl;
            return;
        }
        last[s[l]]--;
        if (last[s[l]] <= 0)
            last.erase(s[l]);
        l++, r++;
    }
    cout << -1 << endl;
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