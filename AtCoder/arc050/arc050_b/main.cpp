#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
void dump(vector<ll> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}

int64_t R, B, x, y;

bool check(ll X) {
  ll r = R - X;
  ll b = B - X;
  if (r < 0 || b < 0) {
    return false;
  }
  ll num = r / (x - 1) + b / (y - 1);
  return (num >= X);
}

int64_t solve() {
  // TODO: edit here
  ll ok = 0;
  ll ng = 1e18 + 1;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (check(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

// generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> R >> B >> x >> y;
  auto ans = solve();
  std::cout << ans << '\n';
  return 0;
}