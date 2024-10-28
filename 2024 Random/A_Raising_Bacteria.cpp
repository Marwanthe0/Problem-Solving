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
    int count = 0;
    while (n > 0)
    {
        cout << n << endl;
        int x = n >> 1;
        if (n % x)
            count++;
        n = x;
    }
    // cout << count + 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}