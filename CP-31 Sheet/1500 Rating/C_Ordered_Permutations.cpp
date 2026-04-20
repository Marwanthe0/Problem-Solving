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
void print(vector<int> &v) {
    for (auto &vl : v)
        cout << vl << " ";
    cout << endl;
    cout << endl;
}
int s(vector<int> &v) {
    int sum = 0, n = v.size();
    for (int i = 0; i < n; i++) {
        int mn = INT_MAX;
        for (int j = i; j < n; j++) {
            mn = min(mn, v[j]);
            sum += mn;
        }
    }
    return sum;
}
void bt(int x) {
    for (int i = 10; i >= 0; i--)
        cerr << (1 & (x >> i));
    cerr << endl;
}
void marwan() {
    int n = 4;
    vector<int> v = {1, 2, 3, 4, 5};
    int count = 1;
    for (int i = 0; i < 120; i++, count++) {
        // if (s(v) == 35 and v[0] == 1)
        int x = s(v);
        if (x == 35)
            cerr << count << endl;
        cout << x << endl;
        print(v);
        next_permutation(all(v));
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}