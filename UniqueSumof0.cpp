#include <iostream>
#include <vector>

std::vector<int> sumZero(int n) {
    std::vector<int> result;

    // Handle even n
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
    }
    // Handle odd n
    else {
        for (int i = 1; i <= n / 2; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        result.push_back(0);
    }

    return result;
}

int main() {
    int n = 6;
    std::vector<int> result = sumZero(n);

    // Print the resulting array
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
