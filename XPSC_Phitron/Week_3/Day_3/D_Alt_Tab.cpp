#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<string, int> a, pair<string, int> b) { return a.second > b.second; }
void marwan()
{
    int n;
    cin >> n;
    unordered_map<string, int> us;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        us[s] = i;
    }
    vector<pair<string, int>> v;
    for (auto vl : us)
        v.push_back(vl);
    sort(v.begin(), v.end(), cmp);
    for (auto vl : v)
        cout << vl.first[vl.first.size() - 2] << vl.first[vl.first.size() - 1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}