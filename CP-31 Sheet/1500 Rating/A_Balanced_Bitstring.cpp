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
#define make_unique v.erase(unique(v.begin(), v.end()), v.end());
void marwan()
{

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '?')
        {
            char x = 'a';
            for (int j = i; j < n; j += k)
            {
                if (s[j] != '?')
                {
                    x = s[j];
                    break;
                }
            }
            if (x != 'a')
            {
                s[i] = x;
                for (int j = i; j < n; j += k)
                {
                    if (s[j] != '?')
                    {
                        if (s[j] != x)
                        {
                            no;
                            return;
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = i; j < n; j += k)
            {
                if (s[i] == '1')
                {
                    if (s[j] == '0')
                    {
                        no;
                        return;
                    }
                    else if (s[j] == '?')
                        s[j] = '1';
                }
                else if (s[i] == '0')
                {
                    if (s[j] == '1')
                    {
                        no;
                        return;
                    }
                    else if (s[j] == '?')
                        s[j] = '0';
                }
            }
        }
    }
    int l = 0, r = 0, c1 = 0, c0 = 0;
    while (r < n)
    {
        if (s[r] == '1')
            c1++;
        else if (s[r] == '0')
            c0++;
        if (r - l + 1 == k)
        {
            if (c1 > k / 2 || c0 > k / 2)
            {
                no;
                return;
            }
            if (s[l] == '1')
                c1--;
            else if (s[l] == '0')
                c0--;
            l++;
        }
        r++;
    }
    yes;
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