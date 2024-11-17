#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int x, y;
    cin >> x >> y;
    cout << min(x % 3, y % 3) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}