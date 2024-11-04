#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, d = 0, w = 0, l = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            d++;
        else if ((a[i] == 'R' && b[i] == 'S') || (a[i] == 'P' && b[i] == 'R') || (a[i] == 'S' && b[i] == 'P'))
            w++;
        else
            l++;
    }
    if (w > l)
        cout << 0 << endl;
    else
    {
        cout << ((l - w) / 2) + 1 << endl;
    }
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