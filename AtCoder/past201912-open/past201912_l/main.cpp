#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

bool has_bit(int n, int i) {
    return (n & (1 << i)) > 0;
}

// [x1,y1,c1]と[x2,y2,c2]のを結ぶコスト計算
double calc_edge_cost(vector<ll> xyc1, vector<ll> xyc2) {
    ll x1 = xyc1[0];
    ll y1 = xyc1[1];
    ll c1 = xyc1[2];
    ll x2 = xyc2[0];
    ll y2 = xyc2[1];
    ll c2 = xyc2[2];
    double cost = hypot(x1 - x2, y1 - y2);
    // cout << "cost:" << cost << endl;
    // cout << hypot(3.0, 4.0, 2.0) << endl;

    if (c1 != c2) {
        cost *= (double)10.0;
    }
    // cout << "cost in f:" << cost << endl;
    return cost;
}

double solve(int N, int M, const std::vector<int64_t> &x, const std::vector<int64_t> &y, const std::vector<int64_t> &c, const std::vector<int64_t> &X, const std::vector<int64_t> &Y, const std::vector<int64_t> &C) {
    double ans = 1e18;

    ll sz;
    REP(b, (1 << M)) {
        vector<vector<ll>> xyc_use;
        vector<ll> xyc;
        REP(i, N) {
            // 大きな塔は全部使う
            xyc = {x[i], y[i], c[i]};
            xyc_use.push_back(xyc);
        }
        // 小さな塔はbでビットが立っているものだけ使う
        REP(i, M) {
            if (has_bit(b, i)) {
                xyc = {X[i], Y[i], C[i]};
                xyc_use.push_back(xyc);
            }
        }
        sz = xyc_use.size();
        // cout << "sz:" << sz << endl;

        // プリム法で最小全域木を求める
        priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> que;
        vector<bool> used(sz, false);
        pair<double, ll> p1 = make_pair(0.0, 0);
        que.push(p1);
        double res = 0.0;
        double cost;
        while (que.size() > 0) {
            pair<double, ll> top = que.top();
            que.pop();
            cost = top.first;
            ll i = top.second;
            // cout << "cost:" << cost << endl;
            // cout << used[i] << endl;

            if (used[i] == false) {
                res += cost;
                used[i] = true;

                // cout << sz << endl;
                REP(j, sz) {
                    // cout << used[j] << endl;
                    if (used[j] == false) {
                        cost = calc_edge_cost(xyc_use[i], xyc_use[j]);
                        pair<double, ll> p2 = make_pair(cost, j);
                        que.push(p2);
                    }
                }
            }
        }
        ans = min(ans, res);
    }
    return ans;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N;
    std::vector<int64_t> x(N), y(N), c(N);
    std::cin >> M;
    std::vector<int64_t> X(M), Y(M), C(M);
    REP(i, N) {
        std::cin >> x[i] >> y[i] >> c[i];
    }
    REP(i, M) {
        std::cin >> X[i] >> Y[i] >> C[i];
    }
    auto ans = solve(N, M, x, y, c, X, Y, C);
    std::cout << std::fixed;
    std::cout << setprecision(12) << ans << '\n';
    return 0;
}
