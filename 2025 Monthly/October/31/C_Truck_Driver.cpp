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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int l = 0, r = 0, ac = 0, bc = 0;
    set<pair<int, int>> ans;
    while (l <= r && r < n)
    {
        if (s[r] == 'a')
            ac++;
        else
            bc++;
        // cout << ac << " " << bc << endl;
        if (ac >= a)
        {
            cerr << l << " " << r << " " << endl;
            while (bc >= b && l <= r)
            {
                if (s[l] == 'b')
                    bc--;
                else
                    ac--;
                l++;
            }
            if (ac > a && bc < b)
            {
                cerr << "ans" << l << " " << r << endl;
                ans.insert({l, r});
            }
        }
        r++;
    }
    cerr << l << endl;
    cout << ans.size();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}