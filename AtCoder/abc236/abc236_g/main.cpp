#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


std::vector<auto> solve(long long N, int T, long long L, const std::vector<long long> &u, const std::vector<long long> &v) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long N;
    int T;
    long long L;
    std::cin >> N >> T;
    std::vector<long long> u(T), v(T);
    std::cin >> L;
    REP (i, T) {
        std::cin >> u[i] >> v[i];
    }
    auto ans = solve(N, T, L, u, v);
    REP (i, (int)ans.size()) {
        std::cout << X[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}