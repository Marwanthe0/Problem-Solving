#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int f(char a, char b)
{
    int count = a - '0';
    count *= 10;
    count += b - '0';
    return count;
}
void marwan()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((int)(s[i] - '0'))
        {
            t.push_back((s[i] - '0') - 1 + 'a');
        }
        else
        {
            int x = f(s[i - 2], s[i - 1]);
            i -= 2;
            t.push_back((char)(x + 'a' - 1));
        }
    }
    reverse(t.begin(), t.end());
    cout << t << endl;
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