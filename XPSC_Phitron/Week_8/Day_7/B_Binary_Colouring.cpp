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
void marwan()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n)
    {
        if (n % 2)
        {
            if (n % 4 == 1)
                v.push_back(1), n -= 1;
            else
                v.push_back(-1), n += 1;
        }
        else
            v.push_back(0);
        n /= 2;
    }
    cout << v.size() << endl;
    for (auto vl : v)
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