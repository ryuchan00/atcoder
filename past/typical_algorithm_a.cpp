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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
  }

  ll ok = N;
  ll ng = -1;
  ll mid;
  while (abs(ok - ng) > 1) {
    mid = (ok + ng);  // 2
    if (A[mid] >= K) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  if (ok == N) {
    cout << -1 << endl;
  } else {
    cout << ok << endl;
  }
}
