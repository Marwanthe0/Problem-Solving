#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool flag = true;
    int as = 0, at = 0;
    if (n == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
                flag = false;
        }
        if(flag) 
        {
            yes;
            return;
        }
    }
    for (auto c : s)
        if (c == 'a')
            as++;
    for (auto c : t)
        if (c == 'a')
            at++;
    if (as == 0 || at == 0)
    {
        no;
        return;
    }
    else if (as != at)
        no;
    else if (s[0] != t[0])
    {
        no;
    }
    else
    {
        if(s[0] == 'b')
        {
        int cnt1 = 0,cnt2 = 0;
            for(auto c:s)
            {
                if(c == 'b') cnt1++;
                else break;
            }
            for(auto c:t)
            {
                if(c == 'b') cnt2++;
                else break;
            }
            if(cnt1 != cnt2) 
            {
                no;
                return;
            }
        }
        yes;
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