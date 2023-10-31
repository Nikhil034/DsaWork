#include <iostream>
#include <string>
#include<bits/stdc++.h>

void reverseSegment(std::string& word, char ch) {
    // Find the index of the first occurrence of 'ch' in word
    size_t found = word.find(ch);

    // Check if 'ch' exists in the string
    if (found != std::string::npos) {
        // Reverse the segment from index 0 to found (inclusive)
        std::reverse(word.begin(), word.begin() + found + 1);
    }
}

int main() {
    std::string word = "abcdefd";
    char ch = 'd';

    reverseSegment(word, ch);

    std::cout << word << std::endl;

    return 0;
}
