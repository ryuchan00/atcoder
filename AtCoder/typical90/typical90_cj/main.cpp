#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


auto solve(int N, int Q, const std::vector<long long> &A, const std::vector<long long> &X, const std::vector<long long> &Y) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N;
    std::vector<long long> A(N);
    std::cin >> Q;
    std::vector<long long> X(Q), Y(Q);
    REP (i, N) {
        std::cin >> A[i];
    }
    REP (i, Q) {
        std::cin >> X[i] >> Y[i];
    }
    auto ans = solve(N, Q, A, X, Y);
    std::cout << x << '\n';
    REP (i, x) {
        std::cout << B[i] << ' ';
    }
    std::cout << '\n';
    std::cout << y << '\n';
    REP (i, y) {
        std::cout << C[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
