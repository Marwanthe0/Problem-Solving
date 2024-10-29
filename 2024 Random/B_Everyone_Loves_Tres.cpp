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
    if (n == 1 || n == 3)
    {
        cout << -1 << endl;
        return;
    }
    if (n % 3 == 0)
    {
        string s(n - 2, '3');
        s += "66";
        cout << s << endl;
        return;
    }
    if (n == 2)
    {
        cout << 66 << endl;
        return;
    }
    string s = "3366";
    for (int i = 5; i <= n; i++)
    {
        if (i % 3 == 2)
            s.insert(s.begin() + 1, '6');
        else
            s.insert(s.begin(), '3');
    }
    cout << s << endl;
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