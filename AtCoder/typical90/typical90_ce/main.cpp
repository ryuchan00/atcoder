#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


auto solve(long long N, int M, const std::vector<long long> &a, const std::vector<long long> &b, int Q, const std::vector<long long> &x, const std::vector<long long> &y) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long N;
    int M, Q;
    std::cin >> N >> M;
    std::vector<long long> a(M), b(M);
    REP (i, M) {
        std::cin >> a[i] >> b[i];
    }
    std::cin >> Q;
    std::vector<long long> x(Q), y(Q);
    REP (i, Q) {
        std::cin >> x[i] >> y[i];
    }
    auto ans = solve(N, M, a, b, Q, x, y);
    REP (i, Q) {
        std::cout << c[i] << '\n';
    }
    return 0;
}
