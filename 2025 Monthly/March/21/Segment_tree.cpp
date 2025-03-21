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
void init(int n, int b, int e, vector<int> &tree, vector<int> &v)
{
    // cout << n << " " << b << " " << e << endl;
    if (b == e)
    {
        tree[n] = v[b];
        return;
    }
    int left = 2 * n, right = (2 * n) + 1, mid = ((b + e) / 2);
    init(left, b, mid, tree, v);
    init(right, mid + 1, e, tree, v);
    tree[n] = min(tree[left], tree[right]);}
void upd(int n, int b, int e, vector<int> &tree, vector<int> &v, int idx, int val)
{
    if (idx > e || idx < b)
        return;
    if (b == e)
    {
        tree[n] = val;
        return;
    }
    int left = 2 * n, right = 2 * n + 1, mid = (b + e) / 2;
    upd(left, b, mid, tree, v, idx, val);
    upd(right, mid + 1, e, tree, v, idx, val);
    tree[n] = tree[left] + tree[right];
}
int div(int n, int b, int e, vector<int> &tree, vector<int> &v, int x, int y)
{
    if (b > y || e < x)
    {
        return INT_MAX;
    }
    if (b >= x && e <= y)
    {
        return (tree[n] % 3 == 0);
    }
    int left = 2 * n, right = 2 * n + 1, mid = (b + e) / 2;
    return div(left, b, mid, tree, v, x, y) + div(right, mid + 1, e, tree, v, x, y);
}
void marwan(int cs)
{
    int n, op;
    cin >> n >> op;
    vector<int> v(n + 1), tree(n * 10, 0);
    for (int i = 1; i <= n; i++)
        v[i] = 0;
    init(1, 1, n, tree, v);
    while (op--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y, z;
            cin >> y >> z;
            upd(1, 1, n, tree, v, y, z);
        }
        else
        {
            int y, z;
            cin >> y >> z;
            cout << div(1, 1, n, tree, v, y, z) << endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}