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
    int l = 0, r = s.size() - 1;
    bool flag = true;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            r--, l++;
        }
        else
        {
            if (s[l] < s[r])
                break;
            else
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << s << endl;
        return;
    }
    else
    {
        string t = s;
        reverse(t.begin(), t.end());
        cout << t << s << endl;
    }
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