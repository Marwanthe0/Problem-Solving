#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    vector<vector<int>> v;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (i == 0)
        {
            temp.push_back(a[i]);
        }
        else
        {
            if (b[i] <= b[i - 1] && b[i - 1] % b[i] == 0)
            {
                temp.push_back(a[i]);
            }
            else
            {
                v.push_back(temp);
                temp.clear();
                temp.push_back(a[i]);
            }
        }
    }
    if (!temp.empty())
        v.push_back(temp);
    if (*min_element(a.begin(), a.end()) > k)
    {
        cout << 0 << endl;
        return;
    }
    for (auto vc : v)
    {
        for (auto vl : vc)
            cerr << vl << " ";
        cerr << endl;
    }
    int ans = INT_MIN;
    for (auto vc : v)
    {
        cerr << endl;
        int l = 0, r = 0, sz = vc.size(), sum = 0;
        while (l < sz && r < sz)
        {
            sum += vc[r];
            if (sum <= k)
            {
                ans = max(ans, r - l + 1);
            }
            else if (sum > k)
            {
                while (l < r && sum > k)
                {
                    sum -= vc[l++];
                }
                if (sum <= k)
                {
                    ans = max(ans, r - l + 1);
                }
            }
            r++;
        }
    }
    cerr << endl;
    cout << ans << endl;
}
int main()
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