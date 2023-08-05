#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    // int arr[5]={1, 2, 3, 4 ,3};
    // int size=sizeof(arr)/sizeof(arr[0]);
    // int it=0;
    // int count=0;
    // vector<int>vec;

    // for(int i=0;i<size;i++)
    // {
    //     it=i+1;
    //     while(it<size)
    //     {
    //         if(arr[it]==arr[i])
    //         {
    //             count++;
    //             vec.push_back(arr[i]);
    //         }
    //         it++;
    //     }
    // }

    // cout<<"Duplicate="<<count<<" ";

    // for(int m=0;m<vec.size();m++)
    // {
    //     cout<<vec[m]<<", ";
    // }

    //Time complexity is O(n^2)
    //Space complexity is O(n)

    //optimize to O(n) time and O(1) space

    int arr[5] = {1, 2, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < size; i++) {
        int curr = arr[i];
        bool isDuplicate = false;

        // Check if the current element is a duplicate
        for (int j = 0; j < i; j++) {
            if (arr[j] == curr) {
                isDuplicate = true;
                break;
            }
        }

        if (isDuplicate) {
            count++;
            cout << curr << ", ";
        }
    }

    cout << "Duplicate=" << count << " ";


    return 0;
}