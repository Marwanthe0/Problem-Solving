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
    set<int> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int count = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < (count))
            continue;
        else
            count++;
    }
    cout << count - 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}