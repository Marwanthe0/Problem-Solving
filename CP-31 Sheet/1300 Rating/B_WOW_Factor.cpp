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
    string s;
    cin >> s;
    while (s.size() > 1 && !(s[0] == 'v' && s[1] == 'v'))
    {
        s.erase(s.begin());
    }
    while (s.size() > 1 && !(s[s.size() - 1] == 'v' && s[s.size() - 2] == 'v'))
    {
        s.erase(--s.end());
    }
    int n = s.size(), count = 0ll, o = 0ll;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'v')
        {
            count++;
            if (o && count > 1)
            {
                ans.push_back((-1) * o);
                o = 0;
            }
        }
        else
        {
            if (count > 1)
                ans.push_back(count - 1);
            count = 0;
            o++;
        }
    }
    if (count > 1ll)
        ans.push_back(count - 1ll);
    if (ans.empty())
    {
        cout << 0 << endl;
        return;
    }
    int sum = 0ll, answer = 0ll, asum = (long long)ans.front();
    // cerr << sum << " " << asum << endl;
    for (int i = 1; i < ans.size(); i++)
    {
        // cerr << ans[i] << " ";
        if (i % 2 == 0)
        {
            answer += (long long)(ans[i] * sum);
            asum += (long long)ans[i];
        }
        else
        {
            sum += (long long)(-1ll) * ans[i] * asum;
        }
    }
    cout << answer << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}