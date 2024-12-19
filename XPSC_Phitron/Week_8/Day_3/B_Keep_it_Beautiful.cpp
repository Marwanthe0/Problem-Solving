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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int f = v[0], mark = 1, last = v[0];
    string s = "1";
    for (int i = 1; i < n; i++)
    {
        if (mark)
        {
            if (v[i] < last)
            {
                if (v[i] <= f)
                {
                    s.push_back('1');
                    mark = 0;
                    last = v[i];
                }
                else
                    s.push_back('0');
            }
            else
            {
                s.push_back('1');
                last = v[i];
            }
        }
        else
        {
            if (v[i] <= f && v[i] >= last)
            {
                s.push_back('1');
                last = v[i];
            }
            else
                s.push_back('0');
        }
    }
    cout << s << endl;
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