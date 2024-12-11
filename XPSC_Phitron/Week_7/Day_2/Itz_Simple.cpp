#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), --v.end(), 0);
    if (a + v.back() > b + sum)
    {
        cout << "Ved\n";
    }
    else if (a + v.back() < b + sum)
        cout << "Varun\n";
    else
        cout << "Equal\n";
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