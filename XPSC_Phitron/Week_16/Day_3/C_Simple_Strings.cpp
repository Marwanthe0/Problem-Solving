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
    string s;
    cin >> s;
    vector<int> a(26, 0);
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            char c = s[i];
            a[c - 'a']++;
            for (int j = 0; j < 26; j++)
            {
                if (a[j] == 0)
                {
                    if (i < n - 1 && (j + 'a') == s[i + 1])
                        continue;
                    else
                    {
                        s[i] = j + 'a';
                        break;
                    }
                }
            }
            a[c - 'a']--;
        }
    }
    cout << s << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}