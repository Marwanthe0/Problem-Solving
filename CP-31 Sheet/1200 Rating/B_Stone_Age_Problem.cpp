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
    int n, k, sum = 0ll;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    map<int, pair<int, int>> p;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        p[i] = {x, -1};
        sum += x;
    }
    int last = -1ll, t = INT_MIN;
    for (int i = 0ll; i < k; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int idx, val;
            cin >> idx >> val;
            if (p[idx].second > t)
            {
                sum -= p[idx].first;
            }
            else
            {
                sum -= last;
            }
            sum += val;
            p[idx].first = val;
            p[idx].second = i;
        }
        else
        {
            int val;
            cin >> val;
            sum = (long long)(n * val);
            last = (long long)val;
            t = i;
        }
        cout << sum << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}