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
    int n, k;
    cin >> n >> k;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int count = 0;
    while (!s.empty())
    {
        auto last = --s.end();
        int req = ((k + 1) / *last) + ((k + 1) % *last != 0) - 1;
        if (s.size() < req + 1)
            break;
        else
        {
            count++;
            while (req--)
                s.erase(s.begin());
            s.erase(last);
        }
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}