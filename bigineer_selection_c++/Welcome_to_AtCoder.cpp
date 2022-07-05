#include <iostream>
using namespace std;
int main() {
  // 入力
  int a, b;
  cin >> a >> b;
  auto o = ((a * b % 2 == 0) ? "Even" : "Odd");
  // 出力
  cout << o << endl;
  return 0;
}
