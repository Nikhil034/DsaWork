#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> answer(n, 1);
    
    int leftProduct = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] *= leftProduct;
        leftProduct *= nums[i];
    }
    
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return answer;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(nums);

    std::cout << "Resultant Array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
