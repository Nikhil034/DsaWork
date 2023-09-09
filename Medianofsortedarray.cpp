#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums3(nums1.size() + nums2.size());
        
        std::copy(nums1.begin(), nums1.end(), nums3.begin());
        std::copy(nums2.begin(), nums2.end(), nums3.begin() + nums1.size());

        std::sort(nums3.begin(), nums3.end());

        if (nums3.size() % 2 == 0) {
            int n1 = nums3[nums3.size() / 2];
            int n2 = nums3[(nums3.size() / 2) - 1];
            double ans = static_cast<double>(n1 + n2) / 2.0;
            return ans;
        } else {
            return static_cast<double>(nums3[nums3.size() / 2]);
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};

    Solution solution;
    double median = solution.findMedianSortedArrays(nums1, nums2);

    std::cout << "Median = " << median << std::endl;

    return 0;
}
