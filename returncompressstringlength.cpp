#include <vector>
#include <iostream>

int compress(std::vector<char>& chars) {
    int index = 0; // index to track the current position in the compressed array
    int count = 1; // count of consecutive repeating characters

    for (int i = 1; i <= chars.size(); ++i) {
        if (i < chars.size() && chars[i] == chars[i - 1]) {
            // If the current character is the same as the previous one,
            // increment the count.
            ++count;
        } else {
            // If the current character is different from the previous one,
            // add the character and its count to the compressed array.
            chars[index++] = chars[i - 1]; // Add the character

            // If the count is greater than 1, add its digits to the array
            if (count > 1) {
                std::string count_str = std::to_string(count);
                for (char c : count_str) {
                    chars[index++] = c;
                }
            }

            count = 1; // Reset count for the next character
        }
    }

    return index; // Return the new length of the array
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'c'};
    int new_length = compress(chars);
    for (int i = 0; i < new_length; ++i) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
