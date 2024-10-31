#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (!m[s])
        {
            m[s]++;
            no;
        }
        else
            yes;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}