#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int count = v[0] == 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] == 0)
        {
            count++;
        }
        else
        {
            if (v[i] == 3 && v[i - 1] == 1)
            {
                v[i] = 2;
            }
            else if (v[i] == 3 && v[i - 1] == 2)
                v[i] = 1;
            else if (v[i] == v[i - 1] && v[i] != 3)
            {
                count++, v[i] = 0;
            }
        }
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}