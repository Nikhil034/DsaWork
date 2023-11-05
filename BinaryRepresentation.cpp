#include <iostream>
#include <vector>

std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1);

    for (int i = 0; i <= n; ++i) {
        int count = 0;
        int num = i;

        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }

        ans[i] = count;
    }

    return ans;
}

int main() {
    int n = 5;  // Change this value to the desired n
    std::vector<int> result = countBits(n);

    for (int i = 0; i <= n; ++i) {
        std::cout << "ans[" << i << "] = " << result[i] << std::endl;
    }

    return 0;
}
