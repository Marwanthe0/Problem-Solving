#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int search(string pat, string txt)
{
    // code here
    int n = txt.size(), m = pat.size();
    int l = 0, r = 0, count = 0;
    vector<int> s(26, 0), t(26, 0);
    for (auto c : pat)
        t[c - 'a']++;
    while (l < n && r < n)
    {
        char lc = txt[l], rc = txt[r];
        s[rc - 'a']++;
        if (r - l + 1 == m)
        {
            bool flag = true;
            for (int i = 0; i < 26; i++)
            {
                if (s[i] != t[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                count++;
            s[lc - 'a']--;
            r++, l++;
        }
        else
            r++;
    }
    return count;
}
void marwan()
{
    string s, t;
    cin >> s >> t;
    cout << search(t, s) << endl;
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