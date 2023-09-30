#include<iostream>
using namespace std;

// Example isBadVersion function (provided by LeetCode)
bool isBadVersion(int version) {
  // This is just a placeholder. In a real problem, this function
  // would be provided by LeetCode or your implementation.
  return true; // Replace with actual logic.
}

int firstBadVersion(int n) {
  int left = 1;
  int right = n;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isBadVersion(mid)) {
      // The first bad version is on the left side or could be mid itself.
      right = mid;
    } else {
      // The first bad version is on the right side.
      left = mid + 1;
    }
  }

  return left; // Left will be the first bad version.
}

int main() {
  int totalVersions = 5; // Replace with the actual number of versions.
  int firstBad = firstBadVersion(totalVersions);
  cout << "The first bad version is: " << firstBad << endl;
  
  return 0;
}
