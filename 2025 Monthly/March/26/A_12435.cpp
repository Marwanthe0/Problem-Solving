#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    vector<int> v(5);
    for (auto &vl : v)
        cin >> vl;
    int count = 0, ct = 0, tt = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (v[i - 1] == i)
            count++;
        if (v[i - 1] == i - 1)
            ct++;
        if (v[i - 1] == i + 1)
            tt++;
    }
    if (count == 3 && ct == 1 && tt == 1)
        yes;
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}