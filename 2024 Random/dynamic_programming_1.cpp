#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll f[1000];
ll fib(int n)
{
    if (n <= 1)
        return n;
    if (f[n] == -1)
    {
        f[n] = fib(n - 1) + fib(n - 2);
    }
    return f[n];
}
void marwan()
{
    memset(f, -1, sizeof(f));
    int n;
    cin >> n;
    cout << fib(n) << endl;
}
int main()
{
    marwan();
    return 0;
}