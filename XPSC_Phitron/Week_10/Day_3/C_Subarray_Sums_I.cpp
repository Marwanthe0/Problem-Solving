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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll x = 0, l = 0, r = 0, count = 0;
    while (r < n)
    {
        x += v[r];
        if (x >= k)
        {
            if (x == k)
                count++;
            else
            {
                while (x > k)
                    x -= v[l++];
                if (x == k)
                    count++;
            }
            // l++;
        }
        r++;
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}