#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    if (a[0] == '<' && b[0] == '^') {
        no;
        return;
    } else if (a[0] == '>' && b[m - 1] == '^') {
        no;
        return;
    } else if (a[n - 1] == '<' && b[0] == 'v') {
        no;
        return;
    } else if (a[n - 1] == '>' && b[m - 1] == 'v') {
        no;
        return;
    }
    yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}