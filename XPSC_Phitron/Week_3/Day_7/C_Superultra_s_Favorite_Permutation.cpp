#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 100009
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int lo(int x)
{
    if (x % 2)
        return x;
    else
        return x - 1;
}
vector<bool> prime(N, true);
void sieve()
{

    for (int p = 2; p * p <= N; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
void marwan()
{
    int n;
    cin >> n;
    if (n <= 4)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
            cout << i << " ";
    }
    int l = 2;
    bool flag = 0;
    if (prime[lo(n) + l])
    {
        flag = true;
        while ((prime[lo(n) + l]))
        {
            l += 2;
        }
    }
    if (flag)
        cout << l << " ";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            if (flag && i == l)
                continue;
            else
                cout << i << " ";
        }
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}