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
    ll sum = 0, zero = 0, flag = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag == -1 && v[i])
        {
            flag = 1;
        }
        if (flag == 1)
        {
            sum += v[i];
            if (!v[i])
                zero++;
        }
    }
    cout << sum + zero << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}