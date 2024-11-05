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
    bool replaced = true;
    while (replaced)
    {
        replaced = false;
        for (int i = 0; i <= n - 3; i++)
        {
            if ((s[i] == '1' && s[i + 1] == '1'))
            {
                s[i] = '1';
                s[i + 1] = '0';
                s[i + 2] = '0';
                replaced = true;
            }
        }
    }
    for (int i = 0; i + 3 <= n; i++) {
      if (s[i] == '1' && s[i + 2] == '1') {
        s[i] = '1', s[i + 1] = '0', s[i + 2] = '0';
      }
    }
    cout << s << endl;
    /*
    101101
    100100
    
    */
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