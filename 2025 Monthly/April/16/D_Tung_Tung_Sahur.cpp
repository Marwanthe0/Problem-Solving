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
    string a, b;
    cin >> a >> b;
    vector<int> x, y;
    int count = 1;
    for (int i = 1; i < b.size(); i++)
    {
        if (b[i] == b[i - 1])
            count++;
        else
        {
            if (b[i - 1] == 'R')
                y.push_back(-1 * count);
            else
                y.push_back(count);
            count = 1;
        }
    }
    y.push_back(count * ((b.back() == 'R' ? (-1) : 1)));
    count = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == a[i - 1])
            count++;
        else
        {
            if (a[i - 1] == 'R')
                x.push_back(-1 * count);
            else
                x.push_back(count);
            count = 1;
        }
    }
    x.push_back(count * ((a.back() == 'R' ? (-1) : 1)));
    for (auto vl : x)
        cerr << vl << " ";
    cerr << endl;
    for (auto vl : y)
        cerr << vl << " ";
    cerr << endl;
    if (x.size() != y.size())
    {
        no;
        return;
    }
    for (int i = 0; i < x.size(); i++)
    {
        if ((x[i] * y[i]) < 0)
        {
            no;
            return;
        }
        if (abs(y[i]) < abs(x[i]) || abs(y[i]) > abs(2 * x[i]))
        {
            no;
            return;
        }
    }
    yes;
}
int32_t main()
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