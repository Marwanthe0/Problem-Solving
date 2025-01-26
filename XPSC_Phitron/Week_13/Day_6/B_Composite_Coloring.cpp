#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> primes;
    for (int i = 2; i <= 35; i++)
    {
        if (prime(i))
            primes.push_back(i);
    }
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < primes.size(); j++)
        {
            if (v[i] % primes[j] == 0)
            {
                m[primes[j]].push_back(i);
                break;
            }
        }
    }
    cout << m.size() << endl;
    vector<int> ans(n);
    int color = 1;
    for (auto vl : m)
    {
        for (auto pos : vl.second)
        {
            ans[pos] = color;
        }
        color++;
    }
    for (auto vl : ans)
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