#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int up(int n)
{
    if (n == 9)
        return 0;
    else
        return n + 1;
}
int down(int n)
{
    if (n == 0)
        return 9;
    else
        return n - 1;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        string s;
        cin >> s;
        for (int j = 0; j < op; j++)
        {
            if (s[j] == 'U')
                v[i] = down(v[i]);
            else
                v[i] = up(v[i]);
        }
    }
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