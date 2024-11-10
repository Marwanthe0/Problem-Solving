#include <bits/stdc++.h>

using namespace std;

map<char, pair <int, int>> dir = {
  {'N', {0, 1}}, {'E', {1, 0}}, {'S', {0, -1}}, {'W', {-1 , 0}}
};

void marwan () {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  pair<int, int> p = {0, 0};
  for (int i = 0; i < 500; i++) {
    auto d = dir[s[i % n]];
    p.first += d.first, p.second += d.second;
    if (p.first == a && p.second == b) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) marwan();
}
