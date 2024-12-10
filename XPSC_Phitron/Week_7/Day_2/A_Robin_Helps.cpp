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
    int sum = 0, count = 0;
    vector<int> v(n);
    for (auto &vl : v)
    {
        cin >> vl;
        if (vl >= k)
            sum += vl;
        if (sum > 0 && vl == 0)
        {
            sum--;
            count++;
        }
    }
    cout << count << endl;
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