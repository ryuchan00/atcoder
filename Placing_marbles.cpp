#include <iostream>
#include <string>
using namespace std;
int main() {
  string a;
  cin >> a;
  size_t s = a.size();
  int cnt = 0;
  // 出力
  for (int i = 0; s > i; i++) {
    if (a.at(i) == '1') cnt++;
  }
  cout << cnt << endl;
  return 0;
}