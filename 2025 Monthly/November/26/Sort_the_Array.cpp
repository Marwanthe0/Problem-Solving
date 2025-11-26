#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "yes" << endl
#define no cout << "no" << endl
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n), d;
    for (auto &vl : v)
        cin >> vl;
    int start = -1, end = -1;
    for (int i = 1; i < n; i++)
    {
        if (start == -1 && v[i] < v[i - 1])
        {
            start = i - 1;
            while (i < n && v[i] < v[i - 1])
                i++;
            end = i;
        }
        else if (start != -1 && v[i] < v[i - 1])
        {
            no;
            return;
        }
    }
    if (start != -1)
        reverse(v.begin() + start, v.begin() + end);
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    if (is_sorted(all(v)))
    {
        yes;
        if (start != -1)
            cout << start + 1 << " " << end << endl;
        else
            cout << 1 << " " << 1 << endl;
    }
    else
        no;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}