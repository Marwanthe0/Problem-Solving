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
    string s;
    cin >> s;
    s = '0' + s;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
        {
            sum += i - 1;
        }
        else
            sum += n - i;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (n % 2 && i == (n / 2) + 1)
            continue;
        if (i <= n / 2 && s[i] == 'L')
            v.push_back(i);
        else if (i > (n / 2) && s[i] == 'R')
            v.push_back(i);
    }
    int l = 0, r = v.size() - 1;
    vector<ll> ans;
    while (l <= r)
    {
        if (n - v[l] > v[r] - 1)
        {
            sum -= v[l] - 1;
            sum += n - v[l];
            ans.push_back(sum);
            l++;
        }
        else
        {
            sum -= n - v[r];
            sum += v[r] - 1;
            ans.push_back(sum);
            r--;
        }
    }
    // ll last = ans[ans.size() - 1];
    for (int i = 0; i < n; i++)
    {
        if (i < ans.size())
            cout << ans[i] << " ";
        else
            cout << sum << " ";
    }
    cout << endl;
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