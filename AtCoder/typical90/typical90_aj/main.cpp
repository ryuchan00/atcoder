#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


auto solve(int N, int Q, const std::vector<long long> &x, const std::vector<long long> &y, const std::vector<long long> &q) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N;
    std::vector<long long> x(N), y(N);
    std::cin >> Q;
    std::vector<long long> q(Q);
    REP (i, N) {
        std::cin >> x[i] >> y[i];
    }
    REP (i, Q) {
        std::cin >> q[i];
    }
    auto ans = solve(N, Q, x, y, q);
    REP (i, Q) {
        std::cout << a[i] << '\n';
    }
    return 0;
}
