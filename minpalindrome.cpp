#include<iostream>
using namespace std;

int main(){

    int n=14324234,r,rev=0;
    int tmp=n;

    while(n>0)
    {
        r=n%10;
        rev=(rev*10)+r;
        n=n/10;
    }

    if(tmp==rev)
      cout<<"say yes!";
    else
     cout<<"sat no";

    return 0;
}