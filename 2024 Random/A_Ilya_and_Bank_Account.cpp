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
    if (s[0] != '-')
        cout << s << endl;
    else
    {
        if (s[s.size() - 1] > s[s.size() - 2])
        {
            s.erase(--s.end());
        }
        else
            s.erase(s.end() - 2);
        if (s.size() == 2 && s[1] == '0')
            s.erase(s.begin());
        cout << s << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}