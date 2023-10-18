// https://bi.biopapyrus.jp/cpp/syntax/map.html
// これを試してみる
#include <stdio.h>

#include <iostream>
#include <map>
#include <string>

int main(void) {
  std::map<std::string, int> seqLen;

  seqLen["CGAGT"] = 5;
  seqLen["TT"] = 2;
  seqLen["CGATCGTGTC"] = 10;

  for (std::map<std::string, int>::iterator i = seqLen.begin(); i != seqLen.end(); ++i) {
    std::cout << i->first << " => " << i->second << std::endl;
  }
  // CGAGT => 5
  // CGATCGTGTC => 10
  // TT => 2

  // for C++11
  for (auto i = seqLen.begin(); i != seqLen.end(); ++i) {
    std::cout << i->first << " => " << i->second << std::endl;
  }
  // CGAGT => 5
  // CGATCGTGTC => 10
  // TT => 2

  return 0;
}
