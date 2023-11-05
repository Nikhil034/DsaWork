#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";  // Return an empty string if the input vector is empty
    }

    std::string prefix = strs[0];  // Initialize with the first string

    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
            ++j;
        }

        prefix = prefix.substr(0, j);  // Update the prefix to the common part
    }

    return prefix;
}

int main() {
    std::vector<std::string> input = {"flower", "flour", "florence", "florida"};
    std::string common_prefix = longestCommonPrefix(input);

    if (!common_prefix.empty()) {
        std::cout << "Longest common prefix: " << common_prefix << std::endl;
    } else {
        std::cout << "No common prefix found." << std::endl;
    }

    return 0;
}
