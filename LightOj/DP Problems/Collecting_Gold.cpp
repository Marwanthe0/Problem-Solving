#include <bits/stdc++.h>
using namespace std;

struct Point {
    int r, c;
};

inline int dist(const Point &a, const Point &b) {
    return max(abs(a.r - b.r), abs(a.c - b.c));
}

int solve_approx_tsp(vector<Point> &pts) {
    int n = pts.size(); // pts[0] = 'x', pts[1..k] = 'g'
    if (n <= 1)
        return 0;

    // 1. Greedy Nearest Neighbor initial tour
    vector<int> tour;
    vector<bool> vis(n, false);
    int curr = 0;
    vis[0] = true;
    tour.push_back(0);

    for (int step = 1; step < n; step++) {
        int best_nxt = -1, best_d = 1e9;
        for (int i = 1; i < n; i++) {
            if (!vis[i]) {
                int d = dist(pts[curr], pts[i]);
                if (d < best_d) {
                    best_d = d;
                    best_nxt = i;
                }
            }
        }
        vis[best_nxt] = true;
        tour.push_back(best_nxt);
        curr = best_nxt;
    }

    // 2. 2-Opt Local Search (Uncrossing edges)
    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 2; j < n; j++) {
                int a = tour[i], b = tour[i + 1];
                int c = tour[j], d = tour[(j + 1) % n];

                int old_cost = dist(pts[a], pts[b]) + dist(pts[c], pts[d]);
                int new_cost = dist(pts[a], pts[c]) + dist(pts[b], pts[d]);

                if (new_cost < old_cost) {
                    reverse(tour.begin() + i + 1, tour.begin() + j + 1);
                    improved = true;
                }
            }
        }
    }

    // Total tour cost calculate kora
    int total_steps = 0;
    for (int i = 0; i < n; i++) {
        total_steps += dist(pts[tour[i]], pts[tour[(i + 1) % n]]);
    }
    return total_steps;
}