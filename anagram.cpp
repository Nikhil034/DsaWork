#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string s1,string s2)
{
    int slen1=s1.length();
    int slen2=s2.length();
    int flag=0;

    if(slen1==slen2)
    {
        for(int i=0;i<slen1;i++)
        {
            for(int j=0;j<slen2;j++)
            {
                if(s1[i]==s2[j])
                {
                    flag=1;
                    continue;
                    
                }
                else
                {
                    flag=0;
                }
            }
        }
    }
    else
    {
        return false;
    }

    if(flag==1){
        return true;
    }
    else{
        return false;
    }
   
}

int main(){
    
    string ch1,ch2;

    cout<<"Enter a first string:-";
    cin>>ch1;

    cout<<"Enter a second string:-";
    cin>>ch2;

    cout<<isAnagram(ch1,ch2);


    

    return 0;
}