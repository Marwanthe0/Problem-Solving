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
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int l1 = 0, l2 = 0, r1 = matrix.size() - 1, r2 = matrix[0].size() - 1, m;
    while (l1 <= r1)
    {
        m = (r1 + l1) / 2;
        if (target >= matrix[m][0] && target <= matrix[m][r2 - 1])
        {
            break;
        }
        else if (matrix[m][0] > target)
        {
            r1 = m - 1;
        }
        else
            l1 = m + 1;
    }
    cerr << m << endl;
    while (l2 <= r2)
    {
        int m1 = (l2 + r2) / 2;
        if (target == matrix[m][m1])
        {
            return true;
        }
        else if (target > matrix[m][m1])
        {
            l2 = m1 + 1;
        }
        else
            r2 = m1 - 1;
    }
    return false;
}
void marwan()
{
    vector<vector<int>> v = {{1},{2}};
    cout << searchMatrix(v, 1) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}