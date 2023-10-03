#include <iostream>
using namespace std;

int brokenCalculator(int start, int target) {
    int steps = 0;
    
    while (start != target) {
        if (target % 2 == 0 && target > start) {
            target /= 2;
        } else {
            target++;
        }
        steps++;
    }
    
    return steps;
}

int main() {
    int start = 3;
    int target = 10;
    
    int answer = brokenCalculator(start, target);
    
    cout << "Minimum steps to reach target: " << answer << endl;
    
    return 0;
}
