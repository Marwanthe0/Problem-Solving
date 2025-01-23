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
void marwan()
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        map<int, int> m;
        for (int j = 2; j * j <= x; j++)
        {
            while (x % j == 0)
            {
                m[j]++;
                x /= j;
            }
        }
        if (x > 1)
            m[x]++;
        if (m.size() == 2)
            count++;
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}