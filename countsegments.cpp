#include <string>

int countSegments(string s) {
    int count = 0;
    bool inSegment = false;

    // Iterate through each character in the string
    for (char c : s) {
        // If the character is not a space and we're not in a segment, we start a new segment
        if (c != ' ' && !inSegment) {
            inSegment = true;
            count++;
        }
        // If the character is a space and we're in a segment, we end the segment
        else if (c == ' ' && inSegment) {
            inSegment = false;
        }
    }

    return count;
}
