#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = n; i >= 1; i--)
    {
        v.push_back(i);
    }
    int l = 2;
    for (int i = 0; i < k; i++)
    {
        int temp = *(v.begin() + (n - l));
        v.erase(v.begin() + (n - l));
        v.push_back(temp);
        l++;
    }
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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