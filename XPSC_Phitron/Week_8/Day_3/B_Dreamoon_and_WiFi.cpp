#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    string a, b;
    cin >> a >> b;
    ll count = 0, x = 0;
    ll confused = 0;
    for (auto c : a)
    {
        if (c == '+')
            count++;
        else
            count--;
    }
    for (auto c : b)
    {
        if (c == '+')
            x++;
        else if (c == '-')
            x--;
        else
            confused++;
    }
    // cout << confused << " " << count << endl;
    if (!confused)
    {
        if (x == count)
            printf("%f\n", 1.000000000000);
        else
            printf("%f\n", 0.000000000000);
        return;
    }
    ll prb = 0;
    for (ll i = 0; i < (1 << confused); i++)
    {
        ll cnt = 0;
        for (ll j = 0; j < confused; j++)
        {
            if ((i >> j) & 1)
            {
                cnt++;
            }
            else
                cnt--;
        }
        if (cnt + x == count)
            prb++;
    }
    printf("%.10lf\n", (double)prb / (double)(1 << confused));
    // cout << (float)(prb) / (float)(confused) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}