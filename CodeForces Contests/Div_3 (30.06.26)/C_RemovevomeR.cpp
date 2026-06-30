#include <bits/stdc++.h>
using namespace std;
long n, t, en[2], st[2], d[2];
bool kt[2];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (long j = 1; j <= t; j++) {
        cin >> n;
        cin >> s;
        if (n == 1)
            cout << n << "\n";
        else {
            d[0] = d[1] = 0;
            kt[0] = kt[1] = 0;
            for (long i = 0; i < n; i++) {
                en[s[i] - '0'] = i;
                kt[s[i] - '0'] = 1;
            }
            for (long i = n - 1; i >= 0; i--)
                st[s[i] - '0'] = i;
            if ((kt[0]) && (kt[1])) {
                if ((en[1] < st[0]) || (st[1] > en[0]))
                    cout << 2 << "\n";
                else
                    cout << 1 << "\n";
            } else
                cout << 1 << "\n";
        }
    }
}
