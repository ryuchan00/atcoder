#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi =  pair<int, int>;

const std::string FIRST = "First";
const std::string SECOND = "Second";
bool solve(int N, const std::vector<long long> &W, const std::vector<long long> &B) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<long long> W(N), B(N);
    REP (i, N) {
        std::cin >> W[i];
    }
    REP (i, N) {
        std::cin >> B[i];
    }
    auto ans = solve(N, W, B);
    std::cout << (ans ? FIRST : SECOND) << '\n';
    return 0;
}
