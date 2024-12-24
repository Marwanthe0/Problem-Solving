#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    v.push_back(1);
    if (n > 2 || ((n == 1 || n == 2) && (k % 3 == 0)))
        v.push_back(3);
    if (k == 5)
        v.push_back(5);
    if (n > 2 || (n <= 2 && k == 7))
        v.push_back(7);
    if (n > 5 || (n <= 5 && (k * fact(n)) % 9 == 0))
        v.push_back(9);
    for (auto &vl : v)
        cout << vl << " ";
    cout << endl;
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