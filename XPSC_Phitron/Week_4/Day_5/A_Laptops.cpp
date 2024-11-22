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
    vector<pair<int, int>> v(n);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > v[i - 1].first && v[i].second < v[i - 1].second)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Happy Alex\n";
    else
        cout << "Poor Alex\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}