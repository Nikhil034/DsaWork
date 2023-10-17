#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 4, 4, 4, 4};
    int m = 1; // Pattern length
    int k = 3; // Repeated k or more times

    int flag = 0;

    for (int i = 0; i <= arr.size() - m; i++) {
        std::vector<int> pattern(arr.begin() + i, arr.begin() + i + m);
        int count = 0;

        for (int j = 0; j <= arr.size() - m; j++) {
            std::vector<int> subArray(arr.begin() + j, arr.begin() + j + m);
            if (pattern == subArray) {
                count++;
            }
        }

        if (count >= k) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }

    return 0;
}
