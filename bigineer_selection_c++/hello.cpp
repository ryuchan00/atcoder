#include <any>
#include <iostream>
int main() {
  auto s = std::any(123);
  std::cout << std::any_cast<int>(s) << std::endl;  // "123"が標準出力
}