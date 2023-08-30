#include<iostream>
using namespace std;


long int multiplyNumbers(int n) 
{
    if (n>=1)
        return n*multiplyNumbers(n-1);
    else
        return 1;
}

int main()
{

    int a=6;
    cout<<multiplyNumbers(a);
    return 0;
}