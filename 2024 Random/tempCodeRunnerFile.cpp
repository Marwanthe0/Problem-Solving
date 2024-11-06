#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    long double n, k;
    cin >> n >> k;
    vector<long double> v(n);
    for (auto &vl : v)
        cin >> vl;
    long double x = M;
    cout << (long double)(n / k) * M << endl;
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