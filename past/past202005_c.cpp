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

ll slove(ll A, ll R, ll N) {
  // R=1のときNの値を無視してAを返す
  if (R == 1) {
    return A;
  }

  rep(_, N - 1) {
    A *= R;
    if (A > pow(10, 9)) {
      return -1;
    }
  }
  return A;
}

// https://atcoder.jp/contests/past202005-open/tasks/past202005_c

int main() {
  ll A, R, N;
  cin >> A >> R >> N;

  ll ans = slove(A, R, N);

  if (ans == -1) {
    cout << "large" << endl;
  } else {
    cout << ans << endl;
  }
}
