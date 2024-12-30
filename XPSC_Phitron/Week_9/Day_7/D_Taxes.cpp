#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool prime(int n)
{
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void marwan()
{
    int n;
    cin >> n;
    if (prime(n))
        cout << 1 << endl;
    else if (n % 2 == 0 || prime(n - 2))
        cout << 2 << endl;
    else
    {
        cout << 3 << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}