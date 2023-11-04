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

// 区間スケジューリングの練習
// https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_b

int main() {
  ll N;
  cin >> N;

  ll a, b;
  vector<ii> BA(N);
  rep(i, N) {
    cin >> a >> b;
    BA[i] = make_pair(b, a);
  }

  // Vectorの要素がPairの時のsort時の挙動は、
  // -一つ目を昇順にソートする。
  // -一つ目が同一の場合はさらに二つ目を昇順にソートする。
  // pairのソート
  // https://qiita.com/redpeaks33/items/7e024a7a9d36b3959295
  sort(BA.begin(), BA.end());

  ll ans = 0;
  ll last = 0;
  for(const auto& ba : BA) {
    if (last < ba.second) {
      ans++;
      last = ba.first;
    }
  }
  cout << ans << endl;
}
