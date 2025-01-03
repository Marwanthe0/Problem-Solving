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
bool bin_search(vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    int mid = (l + r) / 2;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v[mid] == x)
            return true;
        else if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        if (bin_search(v, x))
            yes;
        else
            no;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}