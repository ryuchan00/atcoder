#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
void solve() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n + 1), w(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(N, 2e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - v[i] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    if (dp[n][i] <= W) ans = max(ans, i);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--)
    solve();
}