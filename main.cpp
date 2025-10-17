#include <iostream>
#include <string>

bool secret_check(const std::string &s) {
    int x = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        x += static_cast<int>(static_cast<unsigned char>(s[i])) * (static_cast<int>(i) + 1);
    }
    return x == 12345;
}

int main() {
    std::string buf;
    if (!(std::cin >> buf)) return 0; // read a whitespace-delimited token
    if (secret_check(buf)) std::cout << "OK\n";
    else std::cout << "NO\n";
    return 0;
}
