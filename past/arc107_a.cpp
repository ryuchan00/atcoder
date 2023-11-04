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

// https://atcoder.jp/contests/arc107/tasks/arc107_a

int main() {
  double A, B, C;
  cin >> A >> B >> C;

  unsigned long long D = ((A * (A + 1.0)) / 2.0);
  unsigned long long E = ((double)(B * (B + 1.0)) / 2.0);
  unsigned long long F = ((double)(C * (C + 1.0)) / 2.0);

  double G = ((A * (A + 1.0)) / 2.0);
  double H = (B * (B + 1.0)) / 2.0;
  double I = (C * (C + 1.0)) / 2.0;

  // cout << A << " " << B << " " << C << endl;
  // cout << ((A * (A + 1.0)) / 2.0) << endl;
  // cout << G << " " << H << " " << I << endl;
  // cout << D << " " << E << " " << F << endl;

  unsigned long long ans = (D * E * F) % 998244353;
  unsigned long long ans2 = ((int)(floor(G) * floor(H) * floor(I))) % 998244353;

  // cout << ans << endl;
  // cout << ans2 << endl;

  const ll mod = 998244353;
  const ll N = 1e6 + 5;
  ll a = A;
  ll b = B;
  ll c = C;

  ll sum_c = 0, sum_a = 0, sum_b = 0, ans3 = 0;
  sum_c = c * (c + 1) / 2;
  sum_a = a * (a + 1) / 2;
  sum_b = b * (b + 1) / 2;
  ans3 = ((sum_a % mod) * (sum_b % mod)) % mod;
  ans3 = ((ans3 % mod) * (sum_c % mod)) % mod;
  // cout << (ans3 % mod) << endl;
  cout << (a * (a + 1) / 2 % mod) * (b * (b + 1) / 2 % mod) % mod * (c * (c + 1) / 2 % mod) % mod;
}
