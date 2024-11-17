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
    string s;
    cin >> s;
    int count = 0, count2 = 0;
    bool flag = s[0] - '0';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && flag)
        {
            count++;
            flag = 0;
        }
        else if (s[i] == '0' && !flag)
        {
            count2++;
            flag = 1;
        }
    }
    // cout << count << " " << count2 << endl;
    cout << min(count, count2) << endl;
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