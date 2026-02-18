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
    int x, n;
    cin >> x >> n;
    multiset<int> ms, m;
    ms.insert(0);
    ms.insert(x);
    m.insert(x);
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        auto it = ms.lower_bound(vl);
        int pore = *it;
        int age = *(--it);
        int dif = pore - age;
        m.erase(m.find(dif));
        m.insert(vl - age);
        m.insert(pore - vl);
        ms.insert(vl);
        cout << *(--m.end()) << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}