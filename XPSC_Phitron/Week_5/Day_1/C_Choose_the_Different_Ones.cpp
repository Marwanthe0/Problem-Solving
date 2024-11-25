#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m, c;
    cin >> n >> m >> c;
    set<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= c)
            a.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x <= c)
            b.insert(x);
    }
    set<int> ans;
    auto it1 = a.begin(), it2 = b.begin();
    bool flag = true;
    int count1 = 0, count2 = 0;
    while (1)
    {
        if (it1 == a.end())
        {
            flag = true;
            break;
        }
        if (it2 == b.end())
        {
            flag = false;
            break;
        }
        if (*it1 < *it2)
        {
            ans.insert(*it1);
            it1++;
            count1++;
        }
        else
        {
            ans.insert(*it2);
            *it2++;
            count2++;
        }
    }
    if (flag)
    {
        while (it2 != b.end())
        {
            ans.insert(*it2);
            it2++;
            count2++;
        }
    }
    else
    {
        while (it1 != a.end())
        {
            ans.insert(*it1);
            it1++;
            count1++;
        }
    }
    if (ans.size() == c && count1 >= c / 2 && count2 >= c / 2)
        yes;
    else
        no;
    cerr << count1 << " " << count2 << endl;
    for (auto vl : ans)
        cerr << vl << " ";
    cerr << endl;
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