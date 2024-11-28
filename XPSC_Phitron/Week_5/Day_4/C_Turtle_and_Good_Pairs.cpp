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
    string t = s, ans;
    sort(t.begin(), t.end());
    int l = 0, r = n - 1;
    while (l <= r)
    {
        ans.push_back(t[l++]);
        ans.push_back(t[r--]);
    }
    if (n % 2)
        ans.pop_back();
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