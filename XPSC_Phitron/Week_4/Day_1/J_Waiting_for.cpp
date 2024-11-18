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
    ll sum = 0;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == 'P')
        {
            ll x;
            cin >> x;
            sum += x;
        }
        else
        {
            ll x;
            cin >> x;
            if (x > sum)
            {
                yes;
                sum = 0;
            }
            else
            {
                no;
                sum -= x;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}