class Solution {
public:
    string reverseVowels(string s) {
        char ch;
        int bgn = 0, end = s.length() - 1;

        while (bgn < end) {
            // Find the first vowel from the beginning
            while (bgn < end && !isVowel(s[bgn])) {
                bgn++;
            }

            // Find the first vowel from the end
            while (bgn < end && !isVowel(s[end])) {
                end--;
            }

            // Swap the vowels
            ch = s[bgn];
            s[bgn] = s[end];
            s[end] = ch;

            // Move to the next pair of characters
            bgn++;
            end--;
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};
