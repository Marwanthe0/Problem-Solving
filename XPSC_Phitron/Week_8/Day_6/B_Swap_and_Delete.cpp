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
    int o = 0, z = 0;
    for (auto c : s)
    {
        if (c == '0')
            z++;
        else
            o++;
    }
    if (o == z)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0' && o > 0)
            {
                t.push_back('1');
                o--;
            }
            else if (s[i] == '0' && o <= 0)
                break;
            if (s[i] == '1' && z > 0)
            {
                t.push_back('0');
                z--;
            }
            else if (s[i] == '1' && z <= 0)
            {
                break;
            }
        }
        cout << s.size() - t.size() << endl;
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