#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;


auto solve(long long a, int b, const std::vector<long long> &c, const std::vector<std::vector<long long> > &d) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long a;
    int b;
    std::cin >> a >> b;
    std::vector<long long> c(b);
    std::vector<std::vector<long long> > d(b, std::vector<long long>((c_i)));
    REP (i, b) {
        std::cin >> c[i];
        REP (j, c_i) {
            std::cin >> d[i][j];
        }
    }
    auto ans = solve(a, b, c, d);
    std::cout << f << '\n';
    REP (i, a) {
        std::cout << h[i] << '\n';
    }
    return 0;
}
