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

vector<vector<int>> edges;
vector<bool> done;
vector<int> length;

// メモ化再帰の実装
int rec(int i) {
  // 計算済みであれば，即座に値を返す
  if (done[i]) {
    return length[i];
  }
  // そうでなければ値を計算する
  length[i] = 0;
  for (const auto& j : edges[i]) {
    length[i] = max(length[i], rec(j) + 1);
  }
  done[i] = true;
  return length[i];
}

int ALL;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> A;
  rep(i, N - 1) {
    vector<int> v;
    string str, s;

    getline(cin, str);

    stringstream ss{str};

    while (getline(ss, s, ' ')) {
      v.push_back(stoi(s));
    }
    // A[i]はA[i][i+1]からスタートするため，0からiまでの(i+1)個のダミーで埋める
    A.push_back(v);
  }

  // 集合としてありえるものの個数,2**N でも同じ
  ALL = 1 << N;
  ALL = 1 << 2;

  // cout << ALL << endl;

  unsigned short short11 = 1024;
  bitset<16> bitset11{short11};
  cout << bitset11 << endl;  // 0b00000100'00000000

  unsigned short short12 = short11 >> 1;  // 512
  bitset<16> bitset12{short12};
  cout << bitset12 << endl;  // 0b00000010'00000000

  unsigned short short13 = short11 >> 10;  // 1
  bitset<16> bitset13{short13};
  cout << bitset13 << endl;  // 0b00000000'00000001

  unsigned short short14 = short11 >> 11;  // 0
  bitset<16> bitset14{short14};
  cout << bitset14 << endl;  // 0b00000000'00000000
}