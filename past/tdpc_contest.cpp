#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; (i) < (n); ++(i))
const int L = 1e5 + 1;
// #define DEBUG;

// https://atcoder.jp/contests/tdpc/tasks/tdpc_contest

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vector<int> ps(N + 1);
  // 1始まりにするために先頭にダミーを入れる
  ps[0] = 0;
  for (int i = 1; i < N + 1; ++i) {
    cin >> ps[i];
  }
  int P = accumulate(ps.begin(), ps.end(), 0);

  vector<vector<bool>> exist(N + 1, vector<bool>(P + 1, false));
  exist[0][0] = true;

  for (int i = 1; i < N + 1; ++i) {
    for (int s = 0; s < P + 1; ++s) {
      if (exist[i - 1][s]) {
        exist[i][s] = true;
      }
      if (s >= ps[i] && exist[i - 1][s - ps[i]]) {
        exist[i][s] = true;
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < P + 1; ++i) {
    if (exist[N][i]) {
      ans++;
    }
  }
  cout << ans << endl;
}