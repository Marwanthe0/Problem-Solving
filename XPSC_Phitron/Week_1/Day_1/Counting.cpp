#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    if (n > m)
        cout << 0 << endl;
    else
        cout << m - n + 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}