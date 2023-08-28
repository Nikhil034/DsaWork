#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void IntersectionFind(int arr1[], int arr2[], int size) {
    vector<int> invec;

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (arr1[i] == arr2[k]) {
                invec.push_back(arr1[i]);
                break;  // Break the inner loop after finding a match
            }
        }
    }

    cout << "-------INTERSECTION-----------\n";

    for (int j = 0; j < invec.size(); j++) {
        cout << invec[j] << " ";
    }
    cout << "\n";
}

void UnionFind(int arr1[], int arr2[], int size) {
    set<int> uniset;  // Using a set to avoid duplicate elements

    for (int i = 0; i < size; i++) {
        uniset.insert(arr1[i]);
        uniset.insert(arr2[i]);
    }

    cout << "-------UNION-----------\n";

    for (const int& num : uniset) {
        cout << num << " ";
    }
}

int main() {

    int arr1[5] = {1, 3, 4, 5, 7};
    int arr2[5] = {2, 3, 5, 6, 9};

    IntersectionFind(arr1, arr2, 5);
    UnionFind(arr1, arr2, 5);

    return 0;
}
