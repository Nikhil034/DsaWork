#include <bits/stdc++.h>
using namespace std;


void subArraySum(int arr[], int n, int sum)
{
    
	for (int i = 0; i < n; i++) {
		int currentSum = arr[i];

		if (currentSum == sum) {
			cout << "Sum found at indexes " << i << endl;
			return;
		}
		else {
			for (int j = i + 1; j < n; j++) {
				currentSum += arr[j];

				if (currentSum == sum) {
					cout << "Sum found between indexes "
						<< i << " and " << j << endl;
					return;
				}
			}
		}
	}
	cout << "No subarray found";
	return;
}

// Driver Code
int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 23;
	subArraySum(arr, n, sum);
	return 0;
}
