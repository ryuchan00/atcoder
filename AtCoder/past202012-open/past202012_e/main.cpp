#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;

const std::string YES = "Yes";
const std::string NO = "No";
bool solve(int a, long long b, const std::vector<std::string> &c, const std::vector<std::string> &d) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a;
    long long b;
    std::cin >> a;
    std::vector<std::string> c(a), d(a);
    std::cin >> b;
    REP (i, a) {
        std::cin >> c[i] >> d[i];
    }
    auto ans = solve(a, b, c, d);
    std::cout << (ans ? YES : NO) << '\n';
    return 0;
}
