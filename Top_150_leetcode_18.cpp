#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
    int hayLen = haystack.length();
    int needleLen = needle.length();

    if (needleLen == 0) {
        return 0; // Empty needle matches at the beginning of the haystack
    }

    for (int i = 0; i <= hayLen - needleLen; ++i) {
        int j;
        for (j = 0; j < needleLen; ++j) {
            if (haystack[i + j] != needle[j]) {
                break; // Characters don't match, break the loop
            }
        }
        if (j == needleLen) {
            return i; // Found the needle in the haystack
        }
    }

    return -1; // Needle not found in haystack
}

int main() {
    std::string haystack = "hello world";
    std::string needle = "world";

    int index = strStr(haystack, needle);
    if (index != -1) {
        std::cout << "Needle found at index: " << index << std::endl;
    } else {
        std::cout << "Needle not found in haystack" << std::endl;
    }

    return 0;
}
