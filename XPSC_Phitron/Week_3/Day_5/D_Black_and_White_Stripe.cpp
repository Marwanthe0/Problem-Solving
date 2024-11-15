#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = 0, r = 0, count = 0, mx = 0;
    while (l < n && r < n)
    {
        if (s[r] == 'B')
            count++;
        if (r - l + 1 == k)
        {
            mx = max(count, mx);
            if (s[l] == 'B')
                count--;
            l++, r++;
        }
        else
            r++;
    }
    cout << ((mx > k) ? 0 : k - mx) << endl;
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