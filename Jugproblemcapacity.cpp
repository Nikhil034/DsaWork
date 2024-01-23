#include <iostream>

// Function to calculate the GCD of two numbers using Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to check if it is possible to measure targetCapacity using the given jugs
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
    // Ensure that the targetCapacity is achievable (a multiple of GCD(jug1Capacity, jug2Capacity))
    if (targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0) {
        // Check if targetCapacity is less than or equal to the total capacity of the jugs
        return targetCapacity <= jug1Capacity + jug2Capacity;
    }

    return false;
}

int main() {
    // Example usage
    int jug1Capacity = 3;
    int jug2Capacity = 5;
    int targetCapacity = 4;

    if (canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity)) {
        std::cout << "It is possible to measure " << targetCapacity << " liters.\n";
    } else {
        std::cout << "It is not possible to measure exactly " << targetCapacity << " liters.\n";
    }

    return 0;
}
