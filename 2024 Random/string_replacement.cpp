#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i && v[i] >= v[i - 1])
            cnt++;
    }
    if (cnt == n - 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        if (*(--v.end()) <= *v.begin() && cnt >= n - 2)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}