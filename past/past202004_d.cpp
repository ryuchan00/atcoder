// https://atcoder.jp/contests/past202004-open/tasks/past202004_d
#include <bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; (i) < (n); ++(i))
#define N 6

bool is_match(string T, string S) {
  if (S.size() < T.size()) {
    return false;
  }
  rep(i, S.size() - T.size() + 1) {
    bool ok = true;
    rep(j, T.size()) {
      if (S[i + j] != T[j] && T[j] != '.') {
        ok = false;
      }
    }
    if (ok) {
      return true;
    }
  }
  return false;
}

int main() {
  string S;
  cin >> S;

  string C = "abcdefghijklmnopqrstuvwxyz.";

  vector<string> M;
  // 長さ1
  rep(i, C.size()) {
      // cout << C.substr(i, 1) << endl;
    if (is_match(C.substr(i, 1), S)) {
      M.push_back(C.substr(i, 1));
    }
  }
  // 長さ2
  rep(i, C.size()) {
    rep(j, C.size()) {
      string T = C.substr(i, 1) + C.substr(j, 1);
      if (is_match(T, S)) {
        M.push_back(T);
      }
    }
  }
  // 長さ3
  rep(i, C.size()) {
    rep(j, C.size()) {
      rep(k, C.size()) {
        string T = C.substr(i, 1) + C.substr(j, 1) + C.substr(k, 1);
        if (is_match(T, S)) {
          M.push_back(T);
        }
      }
    }
  }

  // rep(i,M.size()) {
  //   cout << M[i] << endl;
  // }
  cout << M.size() << endl;
}