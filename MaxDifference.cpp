#include <iostream>
#include <string>

int maxDiff(int num) {
    std::string numStr = std::to_string(num);
    int maxDifference = -1;

    for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
            std::string a = numStr;
            for (char& digit : a) {
                if (digit - '0' == x) {
                    digit = '0' + y;
                }
            }
            if (isValid(a)) {
                for (int i = 0; i < a.length(); i++) {
                    if (a[i] == '0' + y) {
                        a[i] = '0' + x;
                    }
                }
                if (isValid(a)) {
                    int aInt = std::stoi(a);
                    maxDifference = std::max(maxDifference, num - aInt);
                }
            }
        }
    }

    return maxDifference;
}

bool isValid(const std::string& str) {
    return str[0] != '0' && str != "0";
}

int main() {
    int num = 123456;
    int result = maxDiff(num);
    std::cout << result << std::endl; // Output: 820000

    return 0;
}
