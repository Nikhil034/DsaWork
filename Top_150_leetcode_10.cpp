#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class RandomizedSet {
private:
    std::unordered_map<int, int> valToIndex; // Map to store value to index mapping
    std::vector<int> values; // Vector to store values
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false; // Value already exists, return false
        }
        
        values.push_back(val); // Add value to the end of the vector
        valToIndex[val] = values.size() - 1; // Update index in the map
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end()) {
            return false; // Value not found, return false
        }

        int index = valToIndex[val]; // Get index of the value to be removed
        int lastVal = values.back(); // Get the last value in the vector
        values[index] = lastVal; // Replace value at index with the last value
        valToIndex[lastVal] = index; // Update index of lastVal in the map
        values.pop_back(); // Remove the last element in the vector
        valToIndex.erase(val); // Erase val from the map
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size(); // Generate a random index
        return values[randomIndex]; // Return the value at the random index
    }
};

int main() {
    RandomizedSet randomSet;
    randomSet.insert(1);
    randomSet.insert(2);
    randomSet.insert(3);
    randomSet.insert(4);

    std::cout << "Random element: " << randomSet.getRandom() << std::endl;

    randomSet.remove(3);

    std::cout << "Random element after removal: " << randomSet.getRandom() << std::endl;

    return 0;
}
