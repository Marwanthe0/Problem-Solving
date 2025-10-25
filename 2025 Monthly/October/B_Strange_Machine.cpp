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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // auto op1 = [&](int x) return x - 1;
    // auto op2 = [&](int x) return x / 2;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (s[i] == 'B')
            v.push_back(-1);
        else
        {
            while (i < n && s[i] == 'A')
            {
                i++, count++;
            }
            v.push_back(count);
            i--;
        }
    }
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    n = v.size();
    while (k--)
    {
        int x, count = 0, i = 0;
        cin >> x;
        while (x > 0)
        {
            // cerr << i << " "<<v[i % n]<<" " << x << " " << count << endl;
            if (v[i % n] == -1)
            {
                x /= 2;
                count++;
            }
            else
            {
                if (x >= v[i % n])
                {
                    x -= v[i % n];
                    count += v[i % n];
                }
                else
                {
                    count += x, x = 0;
                }
            }
            i++;
        }
        cout << count << endl;
    }
}
int32_t main()
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