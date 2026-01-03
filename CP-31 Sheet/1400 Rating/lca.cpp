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

int minLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = 0, ans = INT_MAX, sum = 0;
    multiset<int> ms;
    while (r < n)
    {
        if (ms.find(nums[r]) == ms.end())
            sum += nums[r];
        ms.insert(nums[r]);
        while (l <= r && sum >= k)
        {
            ans = min(ans, r - l + 1);
            ms.erase(ms.find(nums[l]));
            if (ms.find(nums[l]) == ms.end())
                sum -= nums[l];
            l++;
        }
        r++;
    }
    if (ans != INT_MAX)
    {
        return ans;
    }
    else
        return -1;
}

int findMaxVal(int n, vector<vector<int>> &restrictions, vector<int> &diff)
{
    vector<int> ans(n + 1, 0), pf(n + 10), bf(n + 10);
    ans[0] = 0;
    set<int> st;
    for (auto row : restrictions)
    {
        ans[row[0]] = row[1];
        st.insert(row[0]);
    }
    int l = 0, r = diff.size() - 1;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            pf[i] = pf[i - 1] + diff[l++];
        }
        else
            pf[i] = ans[i], l++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (ans[i] == 0)
        {
            bf[i] = bf[i + 1] + diff[r--];
        }
        else
            bf[i] = ans[i], r--;
    }
    for (int i = 0; i <= n; i++)
        cout << pf[i] << " ";
    cout << endl;
    for (int i = 0; i <= n; i++)
        cout << bf[i] << " ";
    cout << endl;
    return 1;
}
void marwan()
{
    int n, k;
    cin >> n;
    for(int i )
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << minLength(v, k);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}