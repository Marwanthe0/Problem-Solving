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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int highest_bits = 30 ;
    vector<int> bits(highest_bits +1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= highest_bits; j++)
        {
            if ((v[i] >> j) & 1)
            {
                bits[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = highest_bits; i >= 0; i--)
    {
        int need = n - bits[i];
        if (need == 0)
        {
            ans += (1LL << i);
        }
        else if (k >= need)
        {
            ans += (1LL << i);
            k -= need;
        }
    }
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