#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
void dump(vector<ll> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
}
void dump2(vector<vector<ll>> a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

bool has_bit(int n, int i) {
  return (n & (1 << i)) > 0;
}

// 貪欲法の練習
// https://atcoder.jp/contests/past202004-open/tasks/past202004_f

int main() {
  ll N;
  cin >> N;

  vector<vector<ll>> X(N, vector<ll>());

  ll a, b;
  rep(i, N) {
    cin >> a >> b;
    X[a - 1].push_back(b);
  }

  vector<ll> cnt(101, 0);
  ll ans = 0;
  // d日目から
  rep(d, N) {
    rep(b, X[d].size()) {
      // d日目から実行可能になるタスクをcntに追加する
      cnt[X[d][b]]++;
    }
    // cnt[b]>0である最大のbを探して加算する
    for (int b = 100; b >= 0; b--) {
      if (cnt[b] > 0) {
        ans += b;
        cnt[b]--;
        break;
      }
    }
    cout << ans << endl;
  }
}
