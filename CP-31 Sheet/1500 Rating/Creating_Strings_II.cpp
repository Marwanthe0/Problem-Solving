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
vector<int> fact, ifact;
int mod(int x, int m = M)
{
    return x % m;
}
int binexp(int base, int exp)
{
    int res = 1ll;
    while (exp)
    {
        if (exp & 1)
            res = mod(base * 1ll * res);
        base = mod(base * 1ll * base);
        exp >>= 1;
    }
    return mod(res);
}
void f(int n)
{
    fact.resize(n + 1), ifact.resize(n + 1);
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = mod(fact[i - 1] * i);
        ifact[i] = binexp(fact[i], M - 2);
    }
}
void marwan()
{
    string s;
    cin >> s;
    int n = s.size();
    f(n);
    // for (auto vl : fact)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : ifact)
    //     cerr << vl << " ";
    // cerr << endl;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    int ans = fact[n];
    for (auto [x, y] : m)
    {
        ans *= ifact[y];
        ans = ans % M;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}