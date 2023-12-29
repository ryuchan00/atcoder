#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;

int h[1009];
vector<ll> dp(10009, 0);  // dp[i]: i番目までの山を見たときの、最大

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    REP(i, N) {
        std::cin >> h[i];
    }

    REP3(i, 0, N) {
        // cout << "\nMax Element = "
        //      << *max_element(a.begin(), a.end());
        ll temp = *max_element(dp.begin(), dp.begin() + h[i]);
        dp[h[i]] = temp + 1;
    }

    auto ans = *max_element(dp.begin(), dp.end());
    std::cout << ans << '\n';
    return 0;
}
