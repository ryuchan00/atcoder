#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

vector<vector<ll>> grid_dijkstra(ll H, ll W, const vector<vector<ll>> &a, ll si, ll sj) {
    vector<vector<ll>> dist(H, vector<ll>(W, 1e18));
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> que;
    dist[si][sj] = 0;
    que.push({0, si, sj});
    while (que.size() > 0) {
        vector<ll> q = que.top();
        que.pop();
        ll d = q[0];
        ll i = q[1];
        ll j = q[2];

        if (d > dist[i][j]) {
            continue;
        }
        vector<vector<ll>> travel = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto &t : travel) {
            ll i2 = t[0] + i;
            ll j2 = t[1] + j;
            if (((0 <= i2) && (i2 < H)) && ((0 <= j2) && (j2 < W)) && d + a[i2][j2] < dist[i2][j2]) {
                dist[i2][j2] = d + a[i2][j2];
                que.push({dist[i2][j2], i2, j2});
            }
        }
    }
    return dist;
}

auto solve(ll H, ll W, const vector<vector<ll>> &a) {
    // 左下，右下，右上からの距離を求める
    vector<vector<ll>> dist1 = grid_dijkstra(H, W, a, H - 1, 0);
    vector<vector<ll>> dist2 = grid_dijkstra(H, W, a, H - 1, W - 1);
    vector<vector<ll>> dist3 = grid_dijkstra(H, W, a, 0, W - 1);

    // T字路の交差点を全探索する
    ll ans = 1e18;
    REP(i, H) {
        REP(j, W) {
            ans = min(ans, dist1[i][j] + dist2[i][j] + dist3[i][j] - 2 * a[i][j]);
        }
    }
    return ans;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // failed to analyze input format
    // TODO: edit here
    int H, W;
    std::cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    REP(i, H) {
        REP(j, W) {
            std::cin >> a[i][j];
        }
    }
    auto ans = solve(H, W, a);
    // failed to analyze output format
    // TODO: edit here
    std::cout << ans << '\n';
    return 0;
}
