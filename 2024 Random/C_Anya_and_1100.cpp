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
    bool flag = false;
    if (n < 4)
    {
        flag = false;
    }
    else
    {
        int l, r;
        for (int i = 0; i < n - 3; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
            {
                flag = true;
                l = i, r = i + 4;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
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