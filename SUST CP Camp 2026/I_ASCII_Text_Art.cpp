#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  char c;
  cin >> c;
  string s = R"(#.#.#.#.#.#.#.#.#.#.#.........#.#.#.#.#.#.#.#.#.#.#
............#....#.....##....................#....#
..........#.#.#..#...#....#..................#.#..#
........#...#..#.#..#......#.................#..#.#
......#.....#....#...######..................#....#
....#.......#....#..#........................#....#
......#.....#....#....#............#.....#...#....#
........#...#....#......#........#..#..#..#..#....#
..........#.#....#........#.....#.....#....#.#....#
............#....#..........#..#.............#....#)";
  for (auto ch : s) {
    if (ch == '#')
      cout << c;
    else if (ch == '.')
      cout << " ";
    else
      cout << ch;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  marwan();
  return 0;
}