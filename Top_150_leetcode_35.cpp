#include <iostream>
#include <unordered_map>

bool areIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> sToT;
    std::unordered_map<char, char> tToS;

    for (int i = 0; i < s.length(); ++i) {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT.find(sChar) != sToT.end() && sToT[sChar] != tChar) {
            return false;
        }

        if (tToS.find(tChar) != tToS.end() && tToS[tChar] != sChar) {
            return false;
        }

        sToT[sChar] = tChar;
        tToS[tChar] = sChar;
    }

    return true;
}

int main() {
    std::string s1 = "egg";
    std::string t1 = "add";
    if (areIsomorphic(s1, t1)) {
        std::cout << "Strings are isomorphic.\n";
    } else {
        std::cout << "Strings are not isomorphic.\n";
    }

    std::string s2 = "foo";
    std::string t2 = "bar";
    if (areIsomorphic(s2, t2)) {
        std::cout << "Strings are isomorphic.\n";
    } else {
        std::cout << "Strings are not isomorphic.\n";
    }

    return 0;
}
