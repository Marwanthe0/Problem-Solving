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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> ans;
    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        while (i < n && abs(v[i]) % 2 != abs(v[i - 1]) % 2)
        {
            if (temp.empty())
                temp.push_back(v[i - 1]);
            temp.push_back(v[i]);
            i++;
        }
        ans.push_back(temp);
    }
    int answer = *max_element(all(v));
    for (auto row : ans)
    {
        int sum = 0, mn = 0;
        for (auto vl : row)
        {
            cerr << vl << " ";
            sum += vl;
            answer = max(answer, sum - mn);
            mn = min(mn, sum);
        }
        cerr << endl;
    }
    cerr << endl;
    cout << answer << endl;
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