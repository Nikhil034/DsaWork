#include<iostream>
using namespace std;

int main(){
    int n=10;
    int ft=0,st=1,nt;
    cout<<ft<<","<<st<<",";

    for(int i=2;i<=n;i++)
    {

        nt=ft+st;
        if(i==n)
        {
            cout<<nt;
        }
        else
        {
           cout<<nt<<",";
        }
        ft=st;
        st=nt;
    }

    return 0;
}