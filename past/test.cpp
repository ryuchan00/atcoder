#include <iostream>
#include <string>
#include <vector>
#include <ranges>

int main()
{
	std::vector<std::string> words = { "zero", "one", "two", "three", "four", "five" };

	// 逆順にアクセスするビュー
	for (const auto& word : words | std::views::reverse)
	{
		std::cout << word << '\n';
	}
}