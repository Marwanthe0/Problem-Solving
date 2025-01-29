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
    // getchar();
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int l = 0, r = 0;
    vector<int> ans;
    while (l < n && r < m)
    {
        if (a[l] == 0 && b[r] == 0)
        {
            ans.push_back(0);
            ans.push_back(0);
            k += 2;
            l++, r++;
        }
        else if (a[l] == 0)
        {
            ans.push_back(0);
            k++;
            l++;
        }
        else if (b[r] == 0)
        {
            ans.push_back(0), k++, r++;
        }
        else
        {
            if (a[l] > k && b[r] > k)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                if (a[l] <= k)
                    ans.push_back(a[l++]);
                else if (b[r] <= k)
                    ans.push_back(b[r++]);
            }
        }
    }
    while (l < n)
    {
        if (!a[l])
        {
            k++, ans.push_back(0);
        }
        else
        {
            if (a[l] > k)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                ans.push_back(a[l]);
            }
        }
        l++;
    }
    while (r < m)
    {
        if (!b[r])
        {
            k++, ans.push_back(0);
        }
        else
        {
            if (b[r] > k)
            {
                cout << -1 << endl;
                return;
            }
            else
            {
                ans.push_back(b[r]);
            }
        }
        r++;
    }
    for (auto &vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}