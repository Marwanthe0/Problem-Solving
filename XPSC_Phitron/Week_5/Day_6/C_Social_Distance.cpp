#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k, count = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    int on = -k - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (i - on <= k)
            {
                count--;
            }
            on = i;
        }
        else
        {
            if (i - on > k)
            {
                count++;
                on = i;
            }
        }
    }
    cout << count << endl;
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