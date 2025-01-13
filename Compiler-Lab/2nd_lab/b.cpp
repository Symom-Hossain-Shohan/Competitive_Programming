#include <iostream>
#include <regex>

int main() {
    std::string str = "The color is red.";
    std::regex pattern("red");

    std::string replaced = std::regex_replace(str, pattern, "blue");
    std::cout << "Replaced string: " << replaced << std::endl;

    return 0;
}
