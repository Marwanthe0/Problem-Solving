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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < (1 << n); i++)
    {
        ll sum = 0;
        for (int k = 0; k < n; k++)
        {
            if ((i >> k) & 1)
            {
                sum += v[k];
            }
            else
                sum -= v[k];
        }
        if (sum % 360 == 0)
        {
            yes;
            return;
        }
    }
    no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}