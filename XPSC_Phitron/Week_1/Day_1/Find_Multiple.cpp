#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    for (int i = a; i <= b; i++)
        if (i % c == 0)
        {
            cout << i << endl;
            return;
        }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}