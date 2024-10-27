#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll s, t;
    cin >> s >> t;
    ll count = 0;
    for (ll i = 0; i <= s; i++)
    {
        for (ll j = 0; j <= s; j++)
        {
            for (ll k = 0; k <= s; k++)
            {
                if (i + j + k <= s && (i * j * k) <= t)
                    count++;
                if ((i + j + k) > s || (i * j * k) > t)
                    break;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}