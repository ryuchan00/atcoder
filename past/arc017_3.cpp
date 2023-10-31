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

// https://atcoder.jp/contests/past201912-open/tasks/past201912_g

int main() {
  ll N, X;
  cin >> N >> X;

  // 偶数と奇数で半分に分ける
  vector<ll> A;
  vector<ll> B;
  int w;
  rep(i, N) {
    cin >> w;
    if (i % 2 == 0) {
      A.push_back(w);
    } else {
      B.push_back(w);
    }
  }

  // グループBを全列挙して重さ合計ごとに集計
  /*
  defaultdictの代わりとしてmapを使う
  // charをキー、intを値として扱う連想配列
  std::map<char, int> m;

  // 挿入
  m.insert(std::make_pair('c', 30));
  m.insert(std::make_pair('a', 10));
  m.insert(std::make_pair('b', 20));

  // 検索 : キー(char)を指定し、値(int)を得る
  int value = m.at('a');
  std::cout << value << std::endl;
  */
  map<ll, ll> dic;
  // vector<ll> dic(1e9 + 1, 0);
  rep(n, (1 << B.size())) {
    int s = 0;
    rep(i, N) {
      if (has_bit(n, i)) {
        s += B[i];
      }
    }
    dic[s] += 1;
  }
  // グループA
  ll ans = 0;
  rep(n, (1 << A.size())) {
    int s = 0;
    rep(i, N) {
      if (has_bit(n, i)) {
        s += A[i];
      }
    }
    ans += dic[X - s];
  }
  // rep(i, dic.size()) {
  //   cout << dic[i] << endl;
  // }
  cout << ans << endl;
}
