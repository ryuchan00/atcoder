#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


double solve(int N, int M, const std::vector<int64_t> &x, const std::vector<int64_t> &y, const std::vector<int64_t> &c, const std::vector<int64_t> &X, const std::vector<int64_t> &Y, const std::vector<int64_t> &C) {
    // TODO: edit here
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
    REP (i, N) {
        std::cin >> x[i] >> y[i] >> c[i];
    }
    REP (i, M) {
        std::cin >> X[i] >> Y[i] >> C[i];
    }
    auto ans = solve(N, M, x, y, c, X, Y, C);
    std::cout << ans << '\n';
    return 0;
}
