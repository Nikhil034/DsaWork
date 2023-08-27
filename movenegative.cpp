#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void move(vector<int>& arr){
sort(arr.begin(),arr.end());
}
int main() {

	vector<int> arr = { -10,11,-12,15,-19,9};
	move(arr);
	for (int e : arr)
	cout<<e << " ";
	return 0;
}


