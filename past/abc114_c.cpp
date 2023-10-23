#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
using ll = long long;
using ii = pair<ll, ll>;
// #define DEBUG;

// https://atcoder.jp/contests/abc114/tasks/abc114_c
// 深さ優先探索の応用

// 数nについて調べ，末尾に数字を追加した数を再帰的に調べる
// use3,use5,use7はそれぞれ3,5,7を使ったかどうかを表すフラグ

ll ans = 0;
ll N;

void dfs(ll n, bool use3, bool use5, bool use7) {
  if (n > N) {
    return;
  }
  if (use3 && use5 && use7) {
    ans++;
  }
  dfs(10 * n + 3, true, use5, use7);
  dfs(10 * n + 5, use3, true, use7);
  dfs(10 * n + 7, use3, use5, true);
}

int main() {
  cin >> N;

  dfs(0, false, false, false);

  cout << ans << endl;
}
