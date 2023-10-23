#include <iostream>
#include<string>
using namespace std;


bool canTurnOffAllBulbs(const string &bulbs, int k, int mid) {
    int n = bulbs.size();
    int operations = 0;
    for (int i = 0; i < n; ++i) {
        if (bulbs[i] == '1') {
            int left = max(0, i - mid + 1);
            int right = min(n - 1, i + mid - 1);
            if (left <= right) {
                operations++;
                i = right;
            }
        }
    }
    return operations <= k;
}

int findMinimumI(int n, int k, const string &bulbs) {
    int low = 1;
    int high = n;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canTurnOffAllBulbs(bulbs, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}



int main() {

	 int n, k;
    cin >> n >> k;
    string bulbs;
    cin >> bulbs;

    int minI = findMinimumI(n, k, bulbs);
    cout << minI << endl;
}