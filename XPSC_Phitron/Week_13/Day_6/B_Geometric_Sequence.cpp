#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan()
{
    long double n;
    cin >> n;
    vector<long double> v(n);
    for (auto &vl : v)
        cin >> vl;
    long double rat = -1;
    for (int i = 1; i < n; i++)
    {
        if (rat == (long double)(-1))
        {
            rat = v[i] / v[i - 1];
        }
        else if ((long double)((long double)v[i] / (long double)v[i - 1]) != (long double)rat)
        {
            no;
            return;
        }
        // cout << (long double)(v[i] / v[i - 1]) << " ";
    }
    yes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}