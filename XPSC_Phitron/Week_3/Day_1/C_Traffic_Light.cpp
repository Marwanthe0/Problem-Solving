#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, ans = INT_MIN;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    if (c == 'g')
    {
        cout << 0 << endl;
        return;
    }
    vector<pair<int, int>> v;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i % n] == c)
            flag = true;
        if (flag)
        {
            if (s[i % n] == 'g')
            {
                ans = max(count, ans);
                count = 0;
                flag = false;
            }
            else
                count++;
        }
        // cout << s[i % n];
    }
    cout << ans << endl;
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