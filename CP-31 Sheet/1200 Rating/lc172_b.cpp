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
int maximumSum(vector<int> &nums)
{
    int n = nums.size(), mx = INT_MIN;
    map<int, multiset<int>> m;
    for (auto vl : nums)
        m[vl % 3].insert(vl);

    if (m.size() == 3)
    {
        mx = *(--m[0].end()) + *(--m[1].end()) + *(--m[2].end());

        int sum = 0;
        if (m.find(0) != m.end())
        {
            if (m[0].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[0].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
            }
            cerr << 0 << "found " << sum << endl;
        }
        mx = max(mx, sum);
        sum = 0;
        if (m.find(1) != m.end())
        {
            if (m[1].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[1].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
                cerr << 1 << "found " << sum << endl;
            }
        }
        mx = max(mx, sum);
        sum = 0;
        if (m.find(2) != m.end())
        {
            if (m[2].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[2].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
                cerr << 1 << "found " << sum << endl;
            }
        }
        mx = max(mx, sum);
        sum = 0;
    }
    else
    {
        int sum = 0;
        if (m.find(0) != m.end())
        {
            if (m[0].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[0].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
            }
            cerr << 0 << "found " << sum << endl;
        }
        mx = max(mx, sum);
        sum = 0;
        if (m.find(1) != m.end())
        {
            if (m[1].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[1].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
                cerr << 1 << "found " << sum << endl;
            }
        }
        mx = max(mx, sum);
        sum = 0;
        if (m.find(2) != m.end())
        {
            if (m[2].size() >= 3)
            {
                int tt = 3;
                for (auto it = m[2].rbegin(); tt > 0; it++, tt--)
                {
                    sum += *it;
                }
                cerr << 1 << "found " << sum << endl;
            }
        }
        mx = max(mx, sum);
        sum = 0;
    }
    return mx;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << maximumSum(v);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}