#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

// Generated by 2.12.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main() {
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  ll sum = 0;
  ll pointer = 0;  // 先頭の位置
  ll q1, q2;
  for (ll i = 0; i < q; i++) {
    cin >> q1 >> q2;
    if (q1 == 1) {
      sum += q2;
    }
    if (q1 == 2) {
      // abcd sum=0のとき pointer=0
      // dabc 1,5,9のとき pointer=3
      // cdab 2,6,10のとき pointer=2
      // bcda 3,7,11のとき pointer=1
      // abcd 0,4,8,12のとき pointer=0
      pointer = (n - (sum % n)) % n;
      cout << s.at((pointer + q2 - 1) % n) << endl;
    }
  }

  return 0;
}