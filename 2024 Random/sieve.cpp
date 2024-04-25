#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 500000
int sieve[500000] = {0};
int prime[500000];
void sive()
{
    for (int i = 2; i * i <= M; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= M; j += i)
            {
                sieve[i] = 1;
            }
        }
    }
    for (int i = 2, j = 0; i <= 500000; i++)
    {
        if (sieve[i] == 0)
        {
            prime[j++] = i;
        }
    }
}
void marwan()
{
    int n;
    cin >> n;
    cout << prime[n] << endl;
}
int main()
{
    sive();
    marwan();
    return 0;
}