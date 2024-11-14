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
    string s, t;
    cin >> s >> t;
    int k = 0, l = 0, r = 1;
    while (l < n)
    {
        char x = s[l], y = s[r];
        while (x != y)
        {
            if (l)
            {
                l--;
                x = s[l];
                y = t[k++];
            }
            else if (r < n - 1)
            {
                r++;
                x = t[k++];
                y = s[r];
            }
        }
        l++, r++;
    }
    cout << k << endl;
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