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
bool solve(int N, long long K, const std::vector<long long> &A, const std::vector<long long> &B) {
    // TODO: edit here
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    long long K;
    std::cin >> N;
    std::vector<long long> A(N), B(N);
    std::cin >> K;
    REP (i, N) {
        std::cin >> A[i];
    }
    REP (i, N) {
        std::cin >> B[i];
    }
    auto ans = solve(N, K, A, B);
    std::cout << (ans ? YES : NO) << '\n';
    return 0;
}
