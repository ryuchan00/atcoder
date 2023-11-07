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

// 二分探索の練習
// https://atcoder.jp/contests/typical-algorithm/tasks/typical_algorithm_a

int main() {
  ll A, B, X;
  cin >> A >> B >> X;
  ll ok = 0;
  ll ng = 1e9 + 1;

  ll mid, d, price;
  while (abs(ok - ng) > 1) {
    mid = (ok + ng) / 2;
    d = to_string(mid).size();
    price = A * mid + B * d;
    if (price <= X) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << endl;
}
