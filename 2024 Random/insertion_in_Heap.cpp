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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        int cur_ind = v.size() - 1;
        while (cur_ind != 0)
        {
            int parent = (cur_ind - 1) / 2;
            if (v[cur_ind] > v[parent])
                swap(v[cur_ind], v[parent]);
            else
                break;
            cur_ind = parent;
        }
    }
    for (auto &vl : v)
        cout << vl << " ";
}
int main()
{
    marwan();
    return 0;
