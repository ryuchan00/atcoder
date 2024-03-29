#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

string solve(std::string s, std::string t) {
    // DPテーブル
    int dp[3000][3000] = {0};  // 初期値も初期条件も 0

    // DPループ
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
            chmax(dp[i + 1][j + 1], dp[i + 1][j]);
            chmax(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }

    // 復元
    string res = "";
    int i = (int)s.size(), j = (int)t.size();
    while (i > 0 && j > 0) {
        // (i-1, j) -> (i, j) と更新されていた場合
        if (dp[i][j] == dp[i - 1][j]) {
            --i;  // DP の遷移を遡る
        }

        // (i, j-1) -> (i, j) と更新されていた場合
        else if (dp[i][j] == dp[i][j - 1]) {
            --j;  // DP の遷移を遡る
        }

        // (i-1, j-1) -> (i, j) と更新されていた場合
        else {
            res = s[i - 1] + res;  // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
            --i, --j;              // DP の遷移を遡る
        }
    }

    return "a";
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::string s, t;
    // std::cin >> s >> t;
    string ans = solve("cb", "aba");
    // failed to analyze output format
    // TODO: edit here
    std::cout << ans << '\n';
    return 0;
}
