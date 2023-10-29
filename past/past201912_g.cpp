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

bool has_bit(int n, int i) {
  return (n & (1 << i)) > 0;
}

int main() {
  // bitset<4> b1(1);
  // bitset<4> b2(3);
  // cout << b1 << endl;
  // cout << b2 << endl;
  // cout << (b1 & b2) << endl;
  int N;
  cin >> N;

  vector<vector<int>> A;
  rep(i, N - 1) {
    // vector<int> v;
    // string str, s;

    // getline(cin, str);

    // stringstream ss{str};

    // while (getline(ss, s, ' ')) {
    //   v.push_back(stoi(s));
    // }
    vector<int> lst;
    rep(_, N - 1 - i) {
      int a;
      cin >> a;
      lst.push_back(a);
      // cout << a << endl;
    }
    // A[i]はA[i][i+1]からスタートするため，0からiまでの(i+1)個のダミーで埋める
    vector<int> dummy(i + 1, 0);
    dummy.insert(dummy.end(), lst.begin(), lst.end());
    A.push_back(dummy);
  }
  // rep(i,A.size()) {
  //   rep(j,A[i].size()) {
  //     cout << A[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // 集合としてありえるものの個数,2**N でも同じ
  int ALL = 1 << N;

  // happy[n]:nで表現される集合を

  // nで表現される集合に要素iが含まれるか判定してTrue/Falseを返す
  vector<ll> happy(ALL, 0);

  // happyの値を前もって計算する
  // sample1だと64回繰り返されていることが分かる
  rep(n, ALL) {
    // bitset<7> b1(n);
    // cout << b1 << endl;

    rep(i, N) {
      for (int j = i + 1; j < N; j++) {
        if (has_bit(n, i) && has_bit(n, j)) {
          happy[n] += A[i][j];
        }
      }
    }
  }
  // cout << "happy" << endl;
  // cout << ALL << endl;
  // rep(i, ALL) {
  //   cout << happy[i] << endl;
  // }

  // 答えの値
  // 充分に小さな値をとっておく
  ll ans = pow(-10, 9);
  // rep(i,ALL) {
  //   cout << happy[i] << endl;
  // }

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
}
