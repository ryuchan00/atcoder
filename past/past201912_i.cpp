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
  ll N, M;
  cin >> N >> M;

  // 1始まりにするために先頭にダミーを入れる
  vector<ll> A(M + 1, 0);
  vector<ll> B(M + 1, 0);
  vector<vector<ll>> C(M + 1);

  rep(i, M + 1) {
    cin >> A[i + 1] >> B[i + 1];
    rep(j, B[i + 1]) {
      ll c;
      cin >> c;
      C[i + 1].push_back(c);
    }
  }

  dump(A);
  cout << endl;
  dump(B);
  cout << endl;
  dump2(C);

  // vector<ll> S(1, 0);
  // vector<ll> C(1, 0);
  // rep(i, M) {
  //   string s;
  //   ll c;
  //   cin >> s >> c;
  //   ll s_val = 0;
  //   rep(j, N) {
  //     if (s[j] == 'Y') {
  //       s_val = (s_val | 1 << j);
  //     }
  //   }
  //   S.push_back(s_val);
  //   C.push_back(c);
  // }

  // rep(i, S.size()) {
  //   /*
  //   サンプルデータ1の場合
  //   0000 0
  //   0111 100
  //   0011 20
  //   0101 10
  //   0110 25
  //   */
  //   bitset<4> b1(S[i]);
  //   cout << b1 << " ";
  //   cout << C[i] << endl;
  // }
/*
  // 集合としてあり得るものの個数．2**Nでも同じ
  int ALL = 1 << N;

  // cost[i][j]:セットiまで見て揃った部品の集合がnであるときのコスト最小値
  vector<vector<ll>> cost(M + 1, vector<ll>(ALL, 1e18));

  // 初期条件
  cost[0][0] = 0;

  // iが小さいところから順に計算
  for (ll i = 1; i < M + 1; i++) {
    for (ll n = 0; n < ALL; n++) {
      // セットiを買わない
      cost[i][n] = min(cost[i][n], cost[i - 1][n]);
      // セットiを買う
      cost[i][(n | S[i])] = min(cost[i][(n | S[i])], cost[i - 1][n] + C[i]);
    }
  }

  // rep(i, cost.size()) {
  //   rep(j, cost[i].size()) {
  //     cout << cost[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 答えは部品が全部そろっている状態の最小コスト
  // ただし1e18(=初期値より変化なし)
  ll ans = cost[M][ALL - 1];
  if (ans == 1e18) {
    ans = -1;
  }

  cout << ans << endl;
  */
}
