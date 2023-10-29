#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    int i = 0;

    while (i < flowerbed.size()) {
        if (flowerbed[i] == 0) {
            bool canPlantHere = (i == 0 || flowerbed[i - 1] == 0) &&
                                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);

            if (canPlantHere) {
                flowerbed[i] = 1;
                count++;
            }
        }

        i++;
    }

    return count >= n;
}

int main() {
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool canPlant = canPlaceFlowers(flowerbed, n);

    if (canPlant) {
        cout << "You can plant " << n << " flowers without violating the rules." << endl;
    } else {
        cout << "You cannot plant " << n << " flowers without violating the rules." << endl;
    }

    return 0;
}
