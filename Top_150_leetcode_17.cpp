#include <iostream>
#include <string>
#include <vector>

std::string convertToZigzag(const std::string& s, int numRows) {
    if (numRows <= 1 || s.length() <= 1) {
        return s;
    }

    std::vector<std::string> rows(numRows);
    int row = 0;
    int step = 1;

    for (char c : s) {
        rows[row].push_back(c);
        if (row == 0) {
            step = 1;  // Going down
        } else if (row == numRows - 1) {
            step = -1; // Going up
        }
        row += step;
    }

    std::string result;
    for (const std::string& str : rows) {
        result += str;
    }

    return result;
}

int main() {
    std::string input = "PAYPALISHIRING";
    int numRows = 4; // Replace this with the desired number of rows

    std::string zigzag = convertToZigzag(input, numRows);
    std::cout << "Zigzag pattern: " << zigzag << std::endl;

    return 0;
}
