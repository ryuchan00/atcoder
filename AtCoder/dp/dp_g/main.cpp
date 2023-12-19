#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int N, M;

vector<vector<int> > G;  // グラフ

// メモ化再帰
int dp[100100];

int rec(int v) {
    if (dp[v] != -1) return dp[v];  // 更新が終わっている

    int res = 0;
    for (auto nv : G[v]) {
        chmax(res, rec(nv) + 1);
    }

    return dp[v] = res;  // メモしながらreturn
}

int64_t solve(int64_t N, int M, const std::vector<int64_t>& x, const std::vector<int64_t>& y) {
    G.assign(N, vector<int>());

    for (int i = 0; i < M; ++i) {
        G[x[i] - 1].push_back(y[i] - 1);
    }

    for (int v = 0; v < N; ++v) dp[v] = -1;  // 初期化

    // 全ノードを一通り更新
    int res = 0;
    for (int v = 0; v < N; ++v) chmax(res, rec(v));
    return res;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;
    std::vector<int64_t> x(M), y(M);
    REP(i, M) {
        std::cin >> x[i] >> y[i];
    }
    auto ans = solve(N, M, x, y);
    std::cout << ans << '\n';
    return 0;
}
