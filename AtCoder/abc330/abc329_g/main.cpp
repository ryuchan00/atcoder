#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;

constexpr long long MOD = 998244353;
long long solve(int N, int M, long long K, const std::vector<long long> &P, const std::vector<long long> &S, const std::vector<long long> &T) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    long long K;
    std::cin >> N;
    std::vector<long long> P(N - 1);
    std::cin >> M;
    std::vector<long long> S(M), T(M);
    std::cin >> K;
    REP (i, N - 1) {
        std::cin >> P[i];
    }
    REP (i, M) {
        std::cin >> S[i] >> T[i];
    }
    auto ans = solve(N, M, K, P, S, T);
    std::cout << ans << '\n';
    return 0;
}
