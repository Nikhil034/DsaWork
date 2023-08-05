#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main(){

   string str,strp;

   cout<<"Enter a string S=";
   cin>>str;

   cout<<"Enter a string P=";
   cin>>strp;


  for (int len = 1; len <= str.length(); len++)
    {   
        // Pick ending point
        for (int i = 0; i <= str.length() - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point. 
            int j = i + len - 1;     //0+1-1       
            for (int k = i; k <= j; k++)
                cout << str[k];
             
            cout << endl;
        }
    }   
    return 0;
}