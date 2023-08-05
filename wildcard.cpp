#include<iostream>
using namespace std;

int main(){
    string str;
    char ch[2];
    ch[0]='*';
    ch[1]='?';
    int flag=0;

    cout<<"Enter your string:-";
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<2;j++)
        {
           
           if(str[i]==ch[j])
           {
            flag=1;
           }
           else
           {
            flag=0;
           }

        }
    }

    if(flag==1){
        cout<<"Pattern is replace yes!";
    }
    else{
        cout<<"Patter is replace not!";
    }

    
    return 0;
}