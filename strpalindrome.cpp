#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
 }

int main(){
    
    string ch;
    
    cout<<"Enter a string:-";
    getline(cin,ch);
    
    cout<<isPalindrome(ch);

    return 0;
}