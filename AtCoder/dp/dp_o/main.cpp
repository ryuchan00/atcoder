#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;

constexpr int64_t MOD = 1000000007;
int64_t solve(int N, const std::vector<std::vector<int64_t> > &a) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<std::vector<int64_t> > a(N, std::vector<int64_t>((N)));
    REP (j, N) {
        REP (i, N) {
            std::cin >> a[j][i];
        }
    }
    auto ans = solve(N, a);
    std::cout << ans << '\n';
    return 0;
}
