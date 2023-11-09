#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> v = {"7", "3", "6", "2", "6"};
    std::string key = "6";

    std::vector<std::string>::iterator itr = std::find(v.begin(), v.end(), key);

    if (itr != v.cend()) {
        std::cout << "Element present at index " << std::distance(v.begin(), itr) << std::endl;
        size_t index = std::distance(v.begin(), itr);
        std::cout << "index:" << index << std::endl;
    } else {
        std::cout << "Element not found";
    }

    return 0;
}