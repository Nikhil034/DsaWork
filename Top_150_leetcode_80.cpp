#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main() {
    uint32_t num = 43261596; // Example input
    
    cout << "Original number: " << num << endl;
    cout << "Reversed number: " << reverseBits(num) << endl;
    
    return 0;
}
