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

// https://atcoder.jp/contests/abc167/tasks/abc167_c

bool has_bit(int n, int i) {
  return (n & (1 << i)) > 0;
}

int main() {
  ll N, M, X;
  cin >> N >> M >> X;

  vector<ll> C(N);
  vector<vector<ll>> A;
  rep(i, N) {
    vector<ll> lst;
    cin >> C[i];
    rep(j, M) {
      int a;
      cin >> a;
      lst.push_back(a);
    }
    // A[i]はA[i][i+1]からスタートするため，0からiまでの(i+1)個のダミーで埋める
    A.push_back(lst);
  }
  // rep(i, A.size()) {
  //   rep(j, A[i].size()) {
  //     cout << A[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 集合としてありえるものの個数,2**N でも同じ
  ll ALL = 1 << N;

  // happy[n]:nで表現される集合を

  // nで表現される集合に要素iが含まれるか判定してTrue/Falseを返す
  vector<vector<ll>> score(ALL, vector<ll>(M, 0));
  vector<ll> total(ALL, 0);

  rep(n, ALL) {
    // sample1だと64回繰り返されていることが分かる
    // bitset<7> b1(n);
    // cout << b1 << endl;

    rep(i, N) {
      if (has_bit(n, i)) {
        for (int j = 0; j < M; j++) {
          // if (has_bit(n, i) && has_bit(n, j)) {
          score[n][j] += A[i][j];
          // }
        }
        total[n] += C[i];
      }
    }
  }

  // cout << "happy" << endl;
  // cout << ALL << endl;
  // rep(i, ALL) {
  //   cout << total[i] << " ";
  //   rep(j, M) {
  //     cout << score[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 答えの値
  // 充分に大きな値をとっておく
  ll ans = pow(10, 16);
  // rep(i,ALL) {
  //   cout << happy[i] << endl;
  // }
  rep(n, ALL) {
    bool ok = true;
    rep(j, M) {
      if (score[n][j] < X) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    ans = min(ans, total[n]);
  }
  if (ans == pow(10, 16)) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  /*

  rep(n1, ALL) {
    rep(n2, ALL) {
      if ((n1 & n2) > 0) {
        continue;
      }
      bitset<11> n3 = ALL - 1 - (n1 | n2);
      // bitset<7> b1(n3);
      // cout << n3.to_ullong() << endl;
      // cout << happy[n1] << endl;
      // cout << happy[n2] << endl;
      // cout << happy[n3.to_ullong()] << endl;
      // cout << n3.to_ullong() << endl;
      ans = max(ans, happy[n1] + happy[n2] + happy[n3.to_ullong()]);
      if (happy[n1] + happy[n2] + happy[n3.to_ullong()] == 4) {
        // cout << "hoge" << endl;
        // cout << n1 << endl;
        // cout << n2 << endl;
        // cout << n3.to_ullong() << endl;
      }
    }
  }
  cout << ans << endl;
  */
}
