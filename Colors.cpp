#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int countRodsWithAllColors(string rings) {
    unordered_map<int, unordered_set<char>> rods; // Maps rod number to a set of colors
    int count = 0;

    for (int i = 0; i < rings.size(); i += 2) {
        char color = rings[i];
        int rod = rings[i + 1] - '0';

        rods[rod].insert(color);

        if (rods[rod].size() == 3) {
            count++;
        }
    }

    return count;
}

int main() {
    string rings = "R3G2B1R2G1B0";
    int result = countRodsWithAllColors(rings);
    cout << "Number of rods with all three colors: " << result << endl;
    return 0;
}
