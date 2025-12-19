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
void marwan()
{
}
string bits(int n)
{
    string s;
    while (n)
    {
        if (n & 1)
            s += '1';
        else
            s += '0';
        n /= 2;
    }
    reverse(all(s));
    return s;
}
int32_t
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < 200; i++)
    {
        int sum = 0, ans;
        for (int j = 0; j <= i; j++)

        {
            if ((j ^ i) <= i && (j + (i ^ j)) > sum)
            {
                sum = j + (i ^ j);
                ans = max(j, (j ^ i));
            }
        }
        if (i != ans)
        {
            cout << i << " " << ans << endl;
            ;
            cout << bits(i) << endl;
            cout << bits(ans) << endl;
            string t = bits(ans ^ i);
            for (int k = 0; k < bits(ans).size() - t.size(); k++)
                cout << '0';
            cout << t << endl;
        }
    }
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     marwan();
    // }
    return 0;
}