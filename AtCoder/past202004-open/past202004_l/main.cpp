#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


auto solve(int N, int64_t K, int64_t D, const std::vector<int64_t> &A) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int64_t K, D;
    std::cin >> N;
    std::vector<int64_t> A(N);
    std::cin >> K >> D;
    REP (i, N) {
        std::cin >> A[i];
    }
    auto ans = solve(N, K, D, A);
    // failed to analyze output format
    // TODO: edit here
    std::cout << ans << '\n';
    return 0;
}