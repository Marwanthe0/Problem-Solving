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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    int sr = INT_MAX, er = INT_MIN, sc = INT_MAX, ec = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#')
            {
                sr = min(sr, i);
                sc = min(sc, j);
                er = max(er, i);
                ec = max(ec, j);
            }
        }
    }
    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
            if (v[i][j] == '.')
            {
                no;
                return;
            }
    }
    yes;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}