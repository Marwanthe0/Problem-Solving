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
    ll x = 0, y = 0;
    auto it = v.begin(), tt = --v.end();
    int cnt = 0;
    while (it <= tt)
    {
        if (cnt % 2 == 0)
        {
            if (*it > *tt)
            {
                x += *it;
                it++;
            }
            else
            {
                x += *tt;
                tt--;
            }
        }
        else
        {
            if (*it > *tt)
            {
                y += *it;
                it++;
            }
            else
            {
                y += *tt;
                tt--;
            }
        }
        cnt++;
    }
    cout << x << " " << y << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}