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
    bool flag = false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            s.insert(s.begin() + i + 1, (s[i] != 'z') ? (char)(s[i] + 1) : (char)(s[i] - 1));
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        s.push_back((s[s.size() - 1] != 'z') ? (char)(s[s.size() - 1] + 1) : (char)(s[s.size() - 1] - 1));
    }
    cout << s << endl;
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