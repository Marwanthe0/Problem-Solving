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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    vector<int> dif;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] > x)
        {
            dif.push_back(v[i] - v[i - 1]);
        }
    }
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    sort(all(dif));
    int count = 0;
    multiset<int> ms(all(dif));
    for (auto vl : dif)
    {
        // cerr << vl << " ";
        int temp = (vl - 1) / x;
        if (k >= temp)
            k -= temp, count++;
        else
            break;
    }
    cout << ms.size() + 1 - count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}