#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    int k = 0;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < m; i++)
    {
        while (k < n && a[k] < b[i])
        {
            k++;
        }
        cout << k << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}