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
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    int x, y;
    // for (auto vl : v)
    //     cout << vl.first << " " << vl.second << endl;
    // cout << endl;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first == v[i - 1].first && (v[i].second - v[i - 1].second > 1) && abs(v[i].first - v[i].second) != 1)
        {
            x = v[i].first;
            y = v[i].second - 1;
            // cout << "first " << x << " " << y << endl;
            if (x != y)
                break;
        }
        else if ((v[i].first - v[i - 1].first == 1) && (v[i - 1].second != n - 1))
        {
            y = n - 1;
            x = v[i - 1].first;
            // cout << "second " << i << " " << x << " " << y << endl;
            if (x != y)
                break;
        }
    }
    cout << x << " " << y << endl;
    // vector<int> ans;
    // int l = 2, r = 2 * n;
    // while (l < r)
    // {
    //     ans.push_back(l);
    //     ans.push_back(r);
    //     l += 2;
    //     r -= 2;
    // }
    // if(n % 2) ans.push_back(n + 1);
    // // cout << x << " " << y << endl;
    // int mn = min(x, y), mx = max(x, y);
    // if (mn == 1)
    // {
    //     swap(ans[1], ans[y - 1]);
    // }
    // else
    // {
    //     int temp1 = ans[x - 1], temp2 = ans[y - 1];
    //     swap(ans[temp1], ans[0]), swap(ans[temp2], ans[1]);
    // }
    // for (auto vl : ans)
    //     cout << vl << " ";
    // cout << endl;
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