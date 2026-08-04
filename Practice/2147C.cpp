#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
string s;
vector<int> v;
//-2= looking at left, and 2 = looking at right
bool f(int i, int agerta, int eragerta) {
    if (i >= n)
        return true;
    if (v[i])
        return f(i + 1);

    
}
void marwan() {
    cin >> n;
    cin >> s;
    for (auto c : s)
        v.push_back(c - '0');
    bool ans = f(0, -2, -2);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}