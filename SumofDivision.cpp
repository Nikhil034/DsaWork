#include <iostream>
#include <vector>
#include <cmath>

bool hasFourDivisors(int num) {
    int divisors = 0;
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            divisors++;
            if (i * i != num) {
                divisors++;
            }
        }
        if (divisors > 4) {
            return false;
        }
    }
    return divisors == 4;
}

int sumFourDivisors(std::vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        if (hasFourDivisors(num)) {
            sum += num;
        }
    }
    return sum;
}

int main() {
    std::vector<int> nums = {21, 4, 7, 4, 18};
    int result = sumFourDivisors(nums);
    std::cout << "Sum of integers with exactly four divisors: " << result << std::endl;
    return 0;
}
