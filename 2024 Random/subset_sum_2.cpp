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
    ll ans = 0;
    unordered_set<int> ad;
    cin >> n;
    vector<int> v(n);

    for (auto &vl : v)
    {
        cin >> vl;
    }

    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        int k = v[i];

        while (k && ad.count(k))
        {
            k--;
        }

        if (k > 0)
        {
            ans += k;
            ad.insert(k);
        }
    }

    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}