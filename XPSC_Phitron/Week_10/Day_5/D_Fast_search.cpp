#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    sort(all(v));
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        int s = lower_bound(all(v), l) - v.begin();
        int e = upper_bound(all(v), r) - v.begin();
        cout << e - s << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}