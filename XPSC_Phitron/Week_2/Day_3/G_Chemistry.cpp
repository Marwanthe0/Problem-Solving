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
    string s;
    cin >> s;
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    int oc = 0;
    for (auto vl : m)
        if (vl.second % 2)
            oc++;
    if (oc - 1 <= k)
        yes;
    else
        no;
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