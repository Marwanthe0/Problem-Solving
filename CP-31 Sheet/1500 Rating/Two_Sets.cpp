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
    int sum = (n * (n + 1)) / 2;
    if (sum & 1)
    {
        no;
        return;
    }
    yes;
    sum /= 2;
    set<int> a;
    int x = n;
    while (x < sum)
    {
        a.insert(x);
        sum -= x;
        x--;
    }
    x = 1;
    while (sum >= x)
    {
        a.insert(x);
        sum -= x;
        x++;
    }
    cout << a.size() << endl;
    for (auto vl : a)
        cout << vl << " ";
    cout << endl;
    cout << n - a.size() << endl;
    for (int i = 1; i <= n; i++)
    {
        if (a.find(i) == a.end())
            cout << i << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}