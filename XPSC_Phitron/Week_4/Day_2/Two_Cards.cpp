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
    vector<int> a(n), b(n);
    int x = INT_MIN, y = INT_MIN, i1 = -1, i2 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > x)
        {
            x = a[i];
            i1 = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] > y)
        {
            y = b[i];
            i2 = i;
        }
    }
    // cout << x << " " << y << " m" << i1 << " " << i2 << endl;
    if (x > y)
        yes;
    else if (x == y)
    {
        if (i1 != i2)
            no;
        else if (count(b.begin(), b.end(), y) > 1)
            no;
        else
            yes;
    }
    else if (x < y)
    {
        if (count(b.begin(), b.end(), y) > 1)
            no;
        else
            yes;
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