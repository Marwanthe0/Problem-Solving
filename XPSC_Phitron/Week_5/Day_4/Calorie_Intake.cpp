#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (y * z > x)
        cout << -1 << endl;
    else
        cout << x - (y * z) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}