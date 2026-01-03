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
    int n;
    cin >> n;
    vector<bool> marked(n + 10);
    vector<bool> tarked(n + 10);
    for (int i = 1; i <= n; i++)
    {
        marked[i] = false;
        tarked[i] = false;
    }
    for (int i = 1; (i * i) <= n; i++)
    {
        for (int j = i + 1; (j * j) <= n - (i * i); j++)
        {
            if ((i * i) + (j * j) <= n)
            {
                if (marked[(i * i) + (j * j)])
                    tarked[(i * i) + (j * j)] = true;
                else
                    marked[(i * i) + (j * j)] = true;
            }
            else
                break;
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (marked[i] == true && tarked[i] == false)
            count++;
    cout << count << endl;
    for (int i = 1; i <= n; i++)
        if (marked[i] == true && tarked[i] == false)
            cout << i << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}