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
    int n = 5;
    vector<int> v(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 2; i <= n; i++)
    {
        // cout << i << " " << v[i] << endl;
        if (i != v[i])
        {
            if (i - 1 != v[i - 1])
                count++;
        }
    }
    if (count == 1)
        yes;
    else
        no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}