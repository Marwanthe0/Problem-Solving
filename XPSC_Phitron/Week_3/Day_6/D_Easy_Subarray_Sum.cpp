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
    int count = 0, neg = 0, flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            count += neg;
            neg = 0;
            flag = 0;
        }
        else if (v[i] < 0 && !flag)
        {
            neg++;
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