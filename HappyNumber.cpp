#include <iostream>
#include <unordered_set>

int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = getNext(n);
    }
    return n == 1;
}

int main() {
    int n = 19;
    
    if (isHappy(n)) {
        std::cout << "HAPPY NUMBER TRUE RETURN!" << std::endl;
    } else {
        std::cout << "RETURN FALSE!" << std::endl;
    }
    
    return 0;
}
