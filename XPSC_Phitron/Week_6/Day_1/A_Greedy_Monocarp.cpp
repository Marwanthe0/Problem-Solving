#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum >= k)
        {
            if (sum > k)
            {
                sum -= v[i];
                cout << k - sum << endl;
                return;
            }
            else
            {
                cout << sum - k << endl;
                return;
            }
        }
    }
    cout << k - sum << endl;
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